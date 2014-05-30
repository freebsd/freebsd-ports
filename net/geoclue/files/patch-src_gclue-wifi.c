--- src/gclue-wifi.c.orig	2014-04-11 17:20:33.000000000 +0000
+++ src/gclue-wifi.c	2014-05-26 11:09:34.546901854 +0000
@@ -25,11 +25,8 @@
 #include <json-glib/json-glib.h>
 #include <string.h>
 #include <config.h>
-#if GCLUE_USE_NETWORK_MANAGER
-#include <nm-client.h>
-#include <nm-device-wifi.h>
-#endif
 #include "gclue-wifi.h"
+#include "wpa_supplicant-interface.h"
 #include "gclue-config.h"
 #include "gclue-error.h"
 #include "geocode-glib/geocode-location.h"
@@ -45,19 +42,19 @@
  * configuration file so its easy to switch to Google's API.
  **/
 
-#if GCLUE_USE_NETWORK_MANAGER
 static gboolean
 gclue_wifi_start (GClueLocationSource *source);
 static gboolean
 gclue_wifi_stop (GClueLocationSource *source);
-#endif
 
 struct _GClueWifiPrivate {
-#if GCLUE_USE_NETWORK_MANAGER
-        NMClient *client;
-        NMDeviceWifi *wifi_device;
-#endif
-        gulong ap_added_id;
+        WPASupplicant *supplicant;
+        WPAInterface *interface;
+        GHashTable *bss_proxies;
+        GHashTable *ignored_bss_proxies;
+
+        gulong bss_added_id;
+        gulong bss_removed_id;
 
         guint refresh_timeout;
 
@@ -75,12 +72,10 @@
 static SoupMessage *
 gclue_wifi_create_query (GClueWebSource *source,
                          GError        **error);
-#if GCLUE_USE_NETWORK_MANAGER
 static SoupMessage *
 gclue_wifi_create_submit_query (GClueWebSource  *source,
                                 GeocodeLocation *location,
                                 GError         **error);
-#endif
 static GeocodeLocation *
 gclue_wifi_parse_response (GClueWebSource *source,
                            const char     *json,
@@ -91,9 +86,8 @@
 
 G_DEFINE_TYPE (GClueWifi, gclue_wifi, GCLUE_TYPE_WEB_SOURCE)
 
-#if GCLUE_USE_NETWORK_MANAGER
 static void
-disconnect_ap_signals (GClueWifi *wifi);
+disconnect_bss_signals (GClueWifi *wifi);
 
 static void
 gclue_wifi_finalize (GObject *gwifi)
@@ -102,13 +96,12 @@
 
         G_OBJECT_CLASS (gclue_wifi_parent_class)->finalize (gwifi);
 
-        if (wifi->priv->wifi_device != NULL) {
-                disconnect_ap_signals (wifi);
-                wifi->priv->wifi_device = NULL;
-        }
-        g_clear_object (&wifi->priv->client);
+        disconnect_bss_signals (wifi);
+        g_clear_object (&wifi->priv->supplicant);
+        g_clear_object (&wifi->priv->interface);
+        g_clear_pointer (&wifi->priv->bss_proxies, g_hash_table_unref);
+        g_clear_pointer (&wifi->priv->ignored_bss_proxies, g_hash_table_unref);
 }
-#endif
 
 static void
 gclue_wifi_constructed (GObject *object);
@@ -153,25 +146,19 @@
 gclue_wifi_class_init (GClueWifiClass *klass)
 {
         GClueWebSourceClass *web_class = GCLUE_WEB_SOURCE_CLASS (klass);
-#if GCLUE_USE_NETWORK_MANAGER
         GClueLocationSourceClass *source_class = GCLUE_LOCATION_SOURCE_CLASS (klass);
-#endif
         GObjectClass *gwifi_class = G_OBJECT_CLASS (klass);
 
-#if GCLUE_USE_NETWORK_MANAGER
         source_class->start = gclue_wifi_start;
         source_class->stop = gclue_wifi_stop;
         web_class->create_submit_query = gclue_wifi_create_submit_query;
-#endif
         web_class->create_query = gclue_wifi_create_query;
         web_class->parse_response = gclue_wifi_parse_response;
         web_class->get_available_accuracy_level =
                 gclue_wifi_get_available_accuracy_level;
         gwifi_class->get_property = gclue_wifi_get_property;
         gwifi_class->set_property = gclue_wifi_set_property;
-#if GCLUE_USE_NETWORK_MANAGER
         gwifi_class->finalize = gclue_wifi_finalize;
-#endif
         gwifi_class->constructed = gclue_wifi_constructed;
 
         g_type_class_add_private (klass, sizeof (GClueWifiPrivate));
@@ -188,7 +175,6 @@
                                          gParamSpecs[PROP_ACCURACY_LEVEL]);
 }
 
-#if GCLUE_USE_NETWORK_MANAGER
 static gboolean
 on_refresh_timeout (gpointer user_data)
 {
@@ -200,118 +186,259 @@
 }
 
 static void
-on_ap_added (NMDeviceWifi  *device,
-             NMAccessPoint *ap,
-             gpointer       user_data);
+on_bss_added (WPAInterface *object,
+              const gchar  *path,
+              GVariant     *properties,
+              gpointer      user_data);
+
+static char *
+variant_to_string (GVariant *variant, guint *len)
+{
+        guint n_bytes, i;
+        char *ret;
+
+        n_bytes = g_variant_n_children (variant);
+        if (len != NULL)
+                *len = n_bytes;
+        if (n_bytes <= 0)
+                return NULL;
+        ret = g_malloc (n_bytes + 1);
+        ret[n_bytes] = '\0';
+
+        for (i = 0; i < n_bytes; i++)
+                g_variant_get_child (variant,
+                                     i,
+                                     "y",
+                                     &ret[i]);
+
+        return ret;
+}
+
+static char *
+get_ssid_from_bss (WPABSS *bss)
+{
+        GVariant *variant = wpa_bss_get_ssid (bss);
+
+        return variant_to_string (variant, NULL);
+}
+
+static char *
+get_bssid_from_bss (WPABSS *bss)
+{
+        GVariant *variant;
+        char *raw_bssid;
+        char *bssid;
+        guint raw_len, len, i, j;
+
+        variant = wpa_bss_get_bssid (bss);
+
+        raw_bssid = variant_to_string (variant, &raw_len);
+        len = raw_len * 2 + raw_len;
+        bssid = g_malloc (len);
+        for (i = 0, j = 0; i < len; i = i + 3, j++)
+                g_snprintf (bssid + i,
+                            4,
+                           "%02x:",
+                           (unsigned char) raw_bssid[j]);
+        bssid[len - 1] = '\0';
+
+        return bssid;
+}
 
 static void
-on_ap_strength_notify (GObject    *gobject,
-                       GParamSpec *pspec,
-                       gpointer    user_data)
+on_bss_signal_notify (GObject    *gobject,
+                      GParamSpec *pspec,
+                      gpointer    user_data)
 {
         GClueWifi *wifi = GCLUE_WIFI (user_data);
-        NMAccessPoint *ap = NM_ACCESS_POINT (gobject);
+        WPABSS *bss = WPA_BSS (gobject);
+        const char *path;
 
-        if (nm_access_point_get_strength (ap) <= 20) {
-                g_debug ("WiFi AP '%s' still has very low strength (%u)"
+        if (wpa_bss_get_signal (bss) <= -90) {
+                char *bssid = get_bssid_from_bss (bss);
+                g_debug ("WiFi AP '%s' still has very low strength (%u dBm)"
                          ", ignoring again..",
-                         nm_access_point_get_bssid (ap),
-                         nm_access_point_get_strength (ap));
+                         bssid,
+                         wpa_bss_get_signal (bss));
+                g_free (bssid);
                 return;
         }
+        path = g_dbus_proxy_get_object_path (G_DBUS_PROXY (bss));
 
-        g_signal_handlers_disconnect_by_func (G_OBJECT (ap),
-                                              on_ap_strength_notify,
+        g_signal_handlers_disconnect_by_func (G_OBJECT (bss),
+                                              on_bss_signal_notify,
                                               user_data);
-        on_ap_added (wifi->priv->wifi_device, ap, user_data);
+        on_bss_added (WPA_INTERFACE (wifi->priv->interface),
+                      path,
+                      NULL,
+                      user_data);
+
+        g_hash_table_replace (wifi->priv->bss_proxies,
+                              g_strdup (path),
+                              bss);
+        g_hash_table_remove (wifi->priv->ignored_bss_proxies, path);
 }
 
 static gboolean
-should_ignore_ap (NMAccessPoint *ap)
+should_ignore_bss (WPABSS *bss)
 {
-        const GByteArray *ssid;
+        char *ssid, *bssid;
 
-        ssid = nm_access_point_get_ssid (ap);
-        if (ssid == NULL ||
-            (ssid->len >= 6 &&
-             ssid->data[ssid->len - 1] == 'p' &&
-             ssid->data[ssid->len - 2] == 'a' &&
-             ssid->data[ssid->len - 3] == 'm' &&
-             ssid->data[ssid->len - 4] == 'o' &&
-             ssid->data[ssid->len - 5] == 'n' &&
-             ssid->data[ssid->len - 6] == '_')) {
+        ssid = get_ssid_from_bss (bss);
+        bssid = get_bssid_from_bss (bss);
+        if (ssid == NULL || g_str_has_suffix (ssid, "_nomap")) {
                 g_debug ("SSID for WiFi AP '%s' missing or has '_nomap' suffix."
                          ", Ignoring..",
-                         nm_access_point_get_bssid (ap));
+                         bssid);
                 return TRUE;
         }
+        g_free (ssid);
+        g_free (bssid);
 
         return FALSE;
 }
 
 static void
-on_ap_added (NMDeviceWifi  *device,
-             NMAccessPoint *ap,
-             gpointer       user_data)
+on_bss_proxy_ready (GObject      *source_object,
+                    GAsyncResult *res,
+                    gpointer      user_data)
 {
         GClueWifi *wifi = GCLUE_WIFI (user_data);
+        WPABSS *bss;
+        GError *error = NULL;
+        const char *path;
+        char *ssid;
+
+        bss = wpa_bss_proxy_new_for_bus_finish (res, &error);
+        if (bss == NULL) {
+                g_debug ("%s", error->message);
+                g_error_free (error);
 
-        if (wifi->priv->refresh_timeout != 0)
                 return;
-        g_debug ("WiFi AP '%s' added.", nm_access_point_get_bssid (ap));
+        }
+        path = g_dbus_proxy_get_object_path (G_DBUS_PROXY (bss));
+
+        if (should_ignore_bss (bss)) {
+                g_object_unref (bss);
 
-        if (should_ignore_ap (ap))
                 return;
+        }
 
-        if (nm_access_point_get_strength (ap) <= 20) {
-                g_debug ("WiFi AP '%s' has very low strength (%u)"
+        ssid = get_ssid_from_bss (bss);
+        g_debug ("WiFi AP '%s' added.", ssid);
+        g_free (ssid);
+
+        path = g_dbus_proxy_get_object_path (G_DBUS_PROXY (bss));
+        if (wpa_bss_get_signal (bss) <= -90) {
+                char *bssid = get_bssid_from_bss (bss);
+                g_debug ("WiFi AP '%s' has very low strength (%u dBm)"
                          ", ignoring for now..",
-                         nm_access_point_get_bssid (ap),
-                         nm_access_point_get_strength (ap));
-                g_signal_connect (G_OBJECT (ap),
-                                  "notify::strength",
-                                  G_CALLBACK (on_ap_strength_notify),
+                         bssid,
+                         wpa_bss_get_signal (bss));
+                g_free (bssid);
+                g_signal_connect (G_OBJECT (bss),
+                                  "notify::signal",
+                                  G_CALLBACK (on_bss_signal_notify),
                                   user_data);
+                g_hash_table_replace (wifi->priv->ignored_bss_proxies,
+                                      g_strdup (path),
+                                      bss);
                 return;
         }
 
+
         /* There could be multiple devices being added/removed at the same time
          * so we don't immediately call refresh but rather wait 1 second.
          */
+        if (wifi->priv->refresh_timeout != 0)
+                g_source_remove (wifi->priv->refresh_timeout);
         wifi->priv->refresh_timeout = g_timeout_add_seconds (1,
                                                              on_refresh_timeout,
                                                              wifi);
+        g_hash_table_replace (wifi->priv->bss_proxies,
+                              g_strdup (path),
+                              bss);
+}
+
+static void
+on_bss_added (WPAInterface *object,
+              const gchar  *path,
+              GVariant     *properties,
+              gpointer      user_data)
+{
+        wpa_bss_proxy_new_for_bus (G_BUS_TYPE_SYSTEM,
+                                   G_DBUS_PROXY_FLAGS_NONE,
+                                   "fi.w1.wpa_supplicant1",
+                                   path,
+                                   NULL,
+                                   on_bss_proxy_ready,
+                                   user_data);
 }
 
 static void
-connect_ap_signals (GClueWifi *wifi)
+on_bss_removed (WPAInterface *object,
+                const gchar  *path,
+                gpointer      user_data)
+{
+        GClueWifiPrivate *priv = GCLUE_WIFI (user_data)->priv;
+
+        g_hash_table_remove (priv->bss_proxies, path);
+        g_hash_table_remove (priv->ignored_bss_proxies, path);
+}
+
+static void
+connect_bss_signals (GClueWifi *wifi)
 {
         GClueWifiPrivate *priv = wifi->priv;
+        const gchar *const *bss_list;
+        guint i;
 
-        if (priv->ap_added_id != 0 || priv->wifi_device == NULL)
+        if (priv->bss_added_id != 0)
                 return;
+        if (priv->interface == NULL) {
+                if (wifi->priv->accuracy_level == GCLUE_ACCURACY_LEVEL_CITY)
+                        gclue_web_source_refresh (GCLUE_WEB_SOURCE (wifi));
 
-        priv->ap_added_id = g_signal_connect (priv->wifi_device,
-                                              "access-point-added",
-                                              G_CALLBACK (on_ap_added),
+                return;
+        }
+
+        priv->bss_added_id = g_signal_connect (priv->interface,
+                                              "bss-added",
+                                              G_CALLBACK (on_bss_added),
                                               wifi);
+        priv->bss_removed_id = g_signal_connect (priv->interface,
+                                                "bss-removed",
+                                                G_CALLBACK (on_bss_removed),
+                                                wifi);
+
+        bss_list = wpa_interface_get_bsss (WPA_INTERFACE (priv->interface));
+        for (i = 0; bss_list[i] != NULL; i++)
+                on_bss_added (WPA_INTERFACE (priv->interface),
+                              bss_list[i],
+                              NULL,
+                              wifi);
 }
 
 static void
-disconnect_ap_signals (GClueWifi *wifi)
+disconnect_bss_signals (GClueWifi *wifi)
 {
         GClueWifiPrivate *priv = wifi->priv;
 
-        if (priv->ap_added_id == 0 || priv->wifi_device == NULL)
+        if (priv->bss_added_id == 0 || priv->interface == NULL)
                 return;
 
-        g_signal_handler_disconnect (priv->wifi_device, priv->ap_added_id);
-        priv->ap_added_id = 0;
+        g_signal_handler_disconnect (priv->interface, priv->bss_added_id);
+        priv->bss_added_id = 0;
+        g_signal_handler_disconnect (priv->interface, priv->bss_removed_id);
+        priv->bss_removed_id = 0;
 
         if (priv->refresh_timeout != 0) {
                 g_source_remove (priv->refresh_timeout);
                 priv->refresh_timeout = 0;
         }
+
+        g_hash_table_remove_all (wifi->priv->bss_proxies);
+        g_hash_table_remove_all (wifi->priv->ignored_bss_proxies);
 }
 
 static gboolean
@@ -325,7 +452,7 @@
         if (!base_class->start (source))
                 return FALSE;
 
-        connect_ap_signals (GCLUE_WIFI (source));
+        connect_bss_signals (GCLUE_WIFI (source));
         return TRUE;
 }
 
@@ -340,10 +467,9 @@
         if (!base_class->stop (source))
                 return FALSE;
 
-        disconnect_ap_signals (GCLUE_WIFI (source));
+        disconnect_bss_signals (GCLUE_WIFI (source));
         return TRUE;
 }
-#endif
 
 static GClueAccuracyLevel
 gclue_wifi_get_available_accuracy_level (GClueWebSource *source,
@@ -351,103 +477,150 @@
 {
         if (!net_available)
                 return GCLUE_ACCURACY_LEVEL_NONE;
-
-#if GCLUE_USE_NETWORK_MANAGER
-        return (GCLUE_WIFI (source)->priv->wifi_device != NULL)?
-                GCLUE_ACCURACY_LEVEL_STREET :
-                GCLUE_ACCURACY_LEVEL_CITY;
-#else
-        return GCLUE_ACCURACY_LEVEL_CITY;
-#endif
+        else if (GCLUE_WIFI (source)->priv->interface != NULL)
+                return GCLUE_ACCURACY_LEVEL_STREET;
+        else
+                return GCLUE_ACCURACY_LEVEL_CITY;
 }
 
-#if GCLUE_USE_NETWORK_MANAGER
-static void
-on_device_added (NMClient *client,
-                 NMDevice *device,
-                 gpointer  user_data)
+static void
+on_interface_proxy_ready (GObject      *source_object,
+                          GAsyncResult *res,
+                          gpointer      user_data)
 {
         GClueWifi *wifi = GCLUE_WIFI (user_data);
+        WPAInterface *interface;
+        GError *error = NULL;
+
+        interface = wpa_interface_proxy_new_for_bus_finish (res, &error);
+        if (interface == NULL) {
+                g_debug ("%s", error->message);
+                g_error_free (error);
 
-        if (wifi->priv->wifi_device != NULL || !NM_IS_DEVICE_WIFI (device))
                 return;
+        }
 
-        wifi->priv->wifi_device = NM_DEVICE_WIFI (device);
+        if (wifi->priv->interface != NULL) {
+                g_object_unref (interface);
+                return;
+        }
+
+        wifi->priv->interface = interface;
         g_debug ("WiFi device '%s' added.",
-                 nm_device_wifi_get_hw_address (wifi->priv->wifi_device));
+                 wpa_interface_get_ifname (interface));
 
         if (gclue_location_source_get_active (GCLUE_LOCATION_SOURCE (wifi)))
-                connect_ap_signals (wifi);
+                connect_bss_signals (wifi);
+        else
+                gclue_web_source_refresh (GCLUE_WEB_SOURCE (wifi));
+}
 
-        gclue_web_source_refresh (GCLUE_WEB_SOURCE (wifi));
+static void
+on_interface_added (WPASupplicant *supplicant,
+                    const gchar   *path,
+                    GVariant      *properties,
+                    gpointer       user_data)
+{
+        GClueWifi *wifi = GCLUE_WIFI (user_data);
+
+        if (wifi->priv->interface != NULL)
+                return;
+
+        wpa_interface_proxy_new_for_bus (G_BUS_TYPE_SYSTEM,
+                                         G_DBUS_PROXY_FLAGS_NONE,
+                                         "fi.w1.wpa_supplicant1",
+                                         path,
+                                         NULL,
+                                         on_interface_proxy_ready,
+                                         wifi);
 }
 
 static void
-on_device_removed (NMClient *client,
-                   NMDevice *device,
-                   gpointer  user_data)
+on_interface_removed (WPASupplicant *supplicant,
+                      const gchar   *path,
+                      gpointer       user_data)
 {
         GClueWifi *wifi = GCLUE_WIFI (user_data);
+        GClueWifiPrivate *priv = wifi->priv;
+        const char *object_path;
 
-        if (wifi->priv->wifi_device == NULL ||
-            NM_DEVICE (wifi->priv->wifi_device) != device)
+        if (priv->interface == NULL)
                 return;
+
+        object_path = g_dbus_proxy_get_object_path
+                        (G_DBUS_PROXY (priv->interface));
+        if (g_strcmp0 (object_path, path) != 0)
+                return;
+
         g_debug ("WiFi device '%s' removed.",
-                 nm_device_wifi_get_hw_address (wifi->priv->wifi_device));
+                 wpa_interface_get_ifname (priv->interface));
 
-        disconnect_ap_signals (wifi);
-        wifi->priv->wifi_device = NULL;
+        disconnect_bss_signals (wifi);
+        g_clear_object (&wifi->priv->interface);
 
         gclue_web_source_refresh (GCLUE_WEB_SOURCE (wifi));
 }
-#endif
 
 static void
 gclue_wifi_init (GClueWifi *wifi)
 {
         wifi->priv = G_TYPE_INSTANCE_GET_PRIVATE ((wifi), GCLUE_TYPE_WIFI, GClueWifiPrivate);
+
+        wifi->priv->bss_proxies = g_hash_table_new_full (g_str_hash,
+                                                         g_str_equal,
+                                                         g_free,
+                                                         g_object_unref);
+        wifi->priv->ignored_bss_proxies = g_hash_table_new_full (g_str_hash,
+                                                                 g_str_equal,
+                                                                 g_free,
+                                                                 g_object_unref);
 }
 
 static void
 gclue_wifi_constructed (GObject *object)
 {
-#if GCLUE_USE_NETWORK_MANAGER
         GClueWifi *wifi = GCLUE_WIFI (object);
-        const GPtrArray *devices;
-        guint i;
+        GClueWifiPrivate *priv = wifi->priv;
+        const gchar *const *interfaces;
+        GError *error = NULL;
 
         G_OBJECT_CLASS (gclue_wifi_parent_class)->constructed (object);
 
         if (wifi->priv->accuracy_level == GCLUE_ACCURACY_LEVEL_CITY)
                 goto refresh_n_exit;
 
-        wifi->priv->client = nm_client_new (); /* FIXME: We should be using async variant */
-        g_signal_connect (wifi->priv->client,
-                          "device-added",
-                          G_CALLBACK (on_device_added),
-                          wifi);
-        g_signal_connect (wifi->priv->client,
-                          "device-removed",
-                          G_CALLBACK (on_device_removed),
-                          wifi);
-
-        devices = nm_client_get_devices (wifi->priv->client);
-        if (devices == NULL)
+        /* FIXME: We should be using async variant */
+        priv->supplicant = wpa_supplicant_proxy_new_for_bus_sync
+                        (G_BUS_TYPE_SYSTEM,
+                         G_DBUS_PROXY_FLAGS_NONE,
+                         "fi.w1.wpa_supplicant1",
+                         "/fi/w1/wpa_supplicant1",
+                         NULL,
+                         &error);
+        if (priv->supplicant == NULL) {
+                g_warning ("Failed to connect to wpa_supplicant service: %s",
+                           error->message);
+                g_error_free (error);
                 goto refresh_n_exit;
+        }
 
-        for (i = 0; i < devices->len; i++) {
-                NMDevice *device = g_ptr_array_index (devices, i);
-                if (NM_IS_DEVICE_WIFI (device)) {
-                    on_device_added (wifi->priv->client, device, wifi);
+        g_signal_connect (priv->supplicant,
+                          "interface-added",
+                          G_CALLBACK (on_interface_added),
+                          wifi);
+        g_signal_connect (priv->supplicant,
+                          "interface-removed",
+                          G_CALLBACK (on_interface_removed),
+                          wifi);
 
-                    break;
-                }
-        }
+        interfaces = wpa_supplicant_get_interfaces (priv->supplicant);
+        if (interfaces != NULL && interfaces[0] != NULL)
+                on_interface_added (priv->supplicant,
+                                    interfaces[0],
+                                    NULL,
+                                    wifi);
 
 refresh_n_exit:
-#else
-        G_OBJECT_CLASS (gclue_wifi_parent_class)->constructed (object);
-#endif
         gclue_web_source_refresh (GCLUE_WEB_SOURCE (object));
 }
 
@@ -509,14 +682,11 @@
         return gclue_config_get_wifi_url (config);
 }
 
-#if GCLUE_USE_NETWORK_MANAGER
-static const GPtrArray *
-get_ap_list (GClueWifi *wifi,
-             GError   **error)
+static GList *
+get_bss_list (GClueWifi *wifi,
+              GError   **error)
 {
-        const GPtrArray *aps;
-
-        if (wifi->priv->wifi_device == NULL) {
+        if (wifi->priv->interface == NULL) {
                 g_set_error_literal (error,
                                      G_IO_ERROR,
                                      G_IO_ERROR_FAILED,
@@ -524,28 +694,15 @@
                 return NULL;
         }
 
-        aps = nm_device_wifi_get_access_points (wifi->priv->wifi_device);
-        if (aps == NULL || aps->len == 0) {
-                g_set_error_literal (error,
-                                     G_IO_ERROR,
-                                     G_IO_ERROR_FAILED,
-                                     "No WiFi access points around");
-                return NULL;
-        }
-
-        return aps;
+        return g_hash_table_get_values (wifi->priv->bss_proxies);
 }
-#endif
 
 static SoupMessage *
 gclue_wifi_create_query (GClueWebSource *source,
                          GError        **error)
 {
-#if GCLUE_USE_NETWORK_MANAGER
         GClueWifi *wifi = GCLUE_WIFI (source);
-        const GPtrArray *aps; /* As in Access Points */
-        guint i;
-#endif
+        GList *bss_list; /* As in Access Points */
         SoupMessage *ret = NULL;
         JsonBuilder *builder;
         JsonGenerator *generator;
@@ -560,46 +717,35 @@
         json_builder_set_member_name (builder, "wifiAccessPoints");
         json_builder_begin_array (builder);
 
-#if GCLUE_USE_NETWORK_MANAGER
-        aps = get_ap_list (wifi, NULL);
-        if (aps != NULL) {
-                for (i = 0; i < aps->len; i++) {
-                        NMAccessPoint *ap = g_ptr_array_index (aps, i);
-                        const char *mac;
-                        gint8 strength_dbm;
+        bss_list = get_bss_list (wifi, NULL);
+	/* We send pure geoip query using empty object if bss_list is NULL. */
+        if (bss_list != NULL) {
+                GList *iter;
+
+		json_builder_set_member_name (builder, "wifiAccessPoints");
+		json_builder_begin_array (builder);
+
+                for (iter = bss_list; iter != NULL; iter = iter->next) {
+                        WPABSS *bss = WPA_BSS (iter->data);
+                        char *mac;
+                        gint16 strength_dbm;
 
-                        if (should_ignore_ap (ap))
+                        if (should_ignore_bss (bss))
                                 continue;
 
                         json_builder_begin_object (builder);
                         json_builder_set_member_name (builder, "macAddress");
-                        mac = nm_access_point_get_bssid (ap);
+                        mac = get_bssid_from_bss (bss);
                         json_builder_add_string_value (builder, mac);
+                        g_free (mac);
 
                         json_builder_set_member_name (builder, "signalStrength");
-                        strength_dbm = nm_access_point_get_strength (ap) /
-                                       2 - 100;
+                        strength_dbm = wpa_bss_get_signal (bss);
                         json_builder_add_int_value (builder, strength_dbm);
                         json_builder_end_object (builder);
                 }
-        } else {
-#endif
-                /* Pure geoip query */
-
-                /* FIXME: Currently we need a dummy AP entry to work around:
-                 *        https://github.com/mozilla/ichnaea/issues/165
-                 */
-                json_builder_begin_object (builder);
-                json_builder_set_member_name (builder, "macAddress");
-                json_builder_add_string_value (builder, "00:00:00:00:00:00");
-
-                json_builder_set_member_name (builder, "signalStrength");
-                json_builder_add_int_value (builder, -50);
-                json_builder_end_object (builder);
-#if GCLUE_USE_NETWORK_MANAGER
+		json_builder_end_array (builder);
         }
-#endif
-        json_builder_end_array (builder);
         json_builder_end_object (builder);
 
         generator = json_generator_new ();
@@ -679,7 +825,6 @@
         return location;
 }
 
-#if GCLUE_USE_NETWORK_MANAGER
 static char *
 get_submit_config (char **nick)
 {
@@ -703,8 +848,7 @@
         JsonNode *root_node;
         char *data, *timestamp, *url, *nick;
         gsize data_len;
-        const GPtrArray *aps; /* As in Access Points */
-        guint i, frequency;
+        GList *bss_list, *iter; /* As in Access Points */
         gdouble lat, lon, accuracy, altitude;
         GTimeVal tv;
 
@@ -712,8 +856,8 @@
         if (url == NULL)
                 goto out;
 
-        aps = get_ap_list (wifi, error);
-        if (aps == NULL)
+        bss_list = get_bss_list (wifi, error);
+        if (bss_list == NULL)
                 goto out;
 
         builder = json_builder_new ();
@@ -754,25 +898,27 @@
         json_builder_set_member_name (builder, "wifi");
         json_builder_begin_array (builder);
 
-        for (i = 0; i < aps->len; i++) {
-                NMAccessPoint *ap = g_ptr_array_index (aps, i);
-                const char *mac;
-                gint8 strength_dbm;
+        for (iter = bss_list; iter != NULL; iter = iter->next) {
+                WPABSS *bss = WPA_BSS (iter->data);
+                char *mac;
+                gint16 strength_dbm;
+                guint16 frequency;
 
-                if (should_ignore_ap (ap))
+                if (should_ignore_bss (bss))
                         continue;
 
                 json_builder_begin_object (builder);
                 json_builder_set_member_name (builder, "key");
-                mac = nm_access_point_get_bssid (ap);
+                mac = get_bssid_from_bss (bss);
                 json_builder_add_string_value (builder, mac);
+                g_free (mac);
 
                 json_builder_set_member_name (builder, "signal");
-                strength_dbm = nm_access_point_get_strength (ap) / 2 - 100;
+                strength_dbm = wpa_bss_get_signal (bss);
                 json_builder_add_int_value (builder, strength_dbm);
 
                 json_builder_set_member_name (builder, "frequency");
-                frequency = nm_access_point_get_frequency (ap);
+                frequency = wpa_bss_get_frequency (bss);
                 json_builder_add_int_value (builder, frequency);
                 json_builder_end_object (builder);
         }
@@ -807,4 +953,3 @@
 out:
         return ret;
 }
-#endif

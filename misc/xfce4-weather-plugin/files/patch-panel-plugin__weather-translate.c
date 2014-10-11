Make plugin ready for met.no locationforecast-1.2 API (bug #10916).

--- panel-plugin/weather-translate.c.orig	2013-01-24 14:45:10 UTC
+++ panel-plugin/weather-translate.c
@@ -29,6 +29,7 @@
 #include "weather-translate.h"
 
 #define DAY_LOC_N (sizeof(gchar) * 100)
+#define NODATA "NODATA"
 
 
 static const gchar *wdirs[] = {
@@ -169,7 +170,7 @@
 
     { 15, "FOG",                 N_("Fog"),                        N_("Fog")                        },
 
-    /* Symbols 16-19 are used for polar days */
+    /* Symbols 16-19 are used for polar days (unused beginning with API version 1.2) */
     { 16, "SUN",                 N_("Sunny"),                      N_("Clear")                      },
     { 17, "LIGHTCLOUD",          N_("Lightly cloudy"),             N_("Lightly cloudy")             },
     { 18, "LIGHTRAINSUN",        N_("Rain showers"),               N_("Rain showers")               },
@@ -185,6 +186,73 @@
 #define NUM_SYMBOLS (sizeof(symbol_to_desc) / sizeof(symbol_to_desc[0]))
 
 
+/*
+ * API version 1.2, published in May 2014, introduced new symbols. We
+ * try to match these with existing symbols, in order to be compatible
+ * with existing icon themes and to maintain translation completeness.
+ *
+ * See http://api.met.no/weatherapi/weathericon/1.1/documentation
+ * for a list of symbols. For a list of symbols with descriptions,
+ * see http://om.yr.no/forklaring/symbol.
+ */
+gint
+replace_symbol_id(gint id)
+{
+    /* Symbol ids greater than 100 are used for indicating polar
+     * night. These ids are over the ordinary id + 100. Since we
+     * don't support polar icons, we can simply subtract 100 to
+     * get the non-polar symbol ids.
+     */
+    if (id > 100)
+        id -= 100;
+
+    switch (id) {
+    case 24: return 22; /* Light rain showers and thunder */
+    case 25: return 6;  /* Heavy rain showers and thunder */
+    case 26: return 20; /* Light sleet showers and thunder */
+    case 27: return 20; /* Heavy sleet showers and thunder */
+    case 28: return 21; /* Light snow showers and thunder */
+    case 29: return 21; /* Heavy snow showers and thunder */
+    case 30: return 22; /* Light rain and thunder */
+    case 31: return 23; /* Light sleet and thunder */
+    case 32: return 23; /* Heavy sleet and thunder */
+    case 33: return 14; /* Light snow and thunder */
+    case 34: return 14; /* Heavy snow and thunder */
+
+    /* symbols 35-39 are unused */
+
+    case 40: return 5;  /* Light rain showers */
+    case 41: return 5;  /* Heavy rain showers */
+    case 42: return 7;  /* Light sleet showers */
+    case 43: return 7;  /* Heavy sleet showers */
+    case 44: return 8;  /* Light snow showers */
+    case 45: return 8;  /* Heavy snow showers */
+    case 46: return 9;  /* Light rain */
+    case 47: return 12; /* Light sleet */
+    case 48: return 12; /* Heavy sleet */
+    case 49: return 13; /* Light snow */
+    case 50: return 13; /* Heavy snow */
+    default: return id;
+    }
+}
+
+
+const gchar *
+get_symbol_for_id(gint id)
+{
+    if (G_UNLIKELY(id < 1))
+        return NODATA;
+
+    if (id >= NUM_SYMBOLS)
+        id = replace_symbol_id(id);
+
+    if (id < NUM_SYMBOLS)
+        return symbol_to_desc[id-1].symbol;
+
+    return NODATA;
+}
+
+
 const gchar *
 translate_desc(const gchar *desc,
                const gboolean nighttime)

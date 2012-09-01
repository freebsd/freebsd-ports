--- modules/access/dtv/access.c.orig
+++ modules/access/dtv/access.c
@@ -198,7 +198,7 @@ static const char *const polarization_us
     "low noise block-downconverters (LNB) through a DiSEqC 1.0 switch, " \
     "the correct LNB can be selected (1 to 4). " \
     "If there is no switch, this parameter should be 0.")
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 static const int satno_vlc[] = { 0, 1, 2, 3, 4 };
 static const char *const satno_user[] = { N_("Unspecified"),
     "A/1", "B/2", "C/3", "D/4" };
@@ -242,7 +242,7 @@ vlc_module_begin ()
 #endif
                  )
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     add_integer ("dvb-adapter", 0, ADAPTER_TEXT, ADAPTER_LONGTEXT, false)
         change_integer_range (0, 255)
         change_safe ()
@@ -366,7 +366,7 @@ vlc_module_begin ()
         change_integer_range (0, 18)
         change_private ()
         change_safe ()
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     add_bool ("dvb-high-voltage", false,
               HIGH_VOLTAGE_TEXT, HIGH_VOLTAGE_LONGTEXT, false)
 #endif
@@ -380,7 +380,7 @@ vlc_module_begin ()
                  LNB_SWITCH_TEXT, LNB_SWITCH_LONGTEXT, true)
         change_integer_range (0, 0x7fffffff)
     add_obsolete_integer ("dvb-lnb-slof") /* since 2.0.0 */
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     add_integer ("dvb-satno", 0, SATNO_TEXT, SATNO_LONGTEXT, true)
         change_integer_list (satno_vlc, satno_user)
     add_integer ("dvb-tone", -1, TONE_TEXT, TONE_LONGTEXT, true)

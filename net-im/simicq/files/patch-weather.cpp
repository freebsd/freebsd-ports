--- plugins/weather/weather.cpp.orig	Fri Apr  2 12:21:54 2004
+++ plugins/weather/weather.cpp	Fri Apr  2 12:23:55 2004
@@ -534,8 +534,8 @@
     res = res.replace(QRegExp("\\%h"), number(getHumidity()) + "%");
     res = res.replace(QRegExp("\\%w"), number(getWind_speed()) + " " + i18n(getUS()));
     res = res.replace(QRegExp("\\%x"), QString::number(getWind_speed() * 10 / 36) + " " + i18n("m/s"));
-    res = res.replace(QRegExp("\\%g"), getWindGust() ? QString("(") + i18n("gust ") + number(getWindGust()) + i18n(getUS()) + ")" : "");
-    res = res.replace(QRegExp("\\%y"), getWindGust() ? QString("(") + i18n("gust ") + number(getWindGust() * 10 / 36) + " " + i18n("m/s") + ")" : "");
+    res = res.replace(QRegExp("\\%g"), getWindGust() ? QString("(") + i18n("gust ") + number(getWindGust()) + i18n(getUS()) + ")" : QString(""));
+    res = res.replace(QRegExp("\\%y"), getWindGust() ? QString("(") + i18n("gust ") + number(getWindGust() * 10 / 36) + " " + i18n("m/s") + ")" : QString(""));
     res = res.replace(QRegExp("\\%p"), number(getPressure()) + " " + i18n(getUP()));
     res = res.replace(QRegExp("\\%a"), number(getPressure() * 75 / 100));
     res = res.replace(QRegExp("\\%q"), i18n("weather", getPressureD()));
@@ -545,7 +545,7 @@
     res = res.replace(QRegExp("\\%r"), getSun_raise());
     res = res.replace(QRegExp("\\%s"), getSun_set());
     res = res.replace(QRegExp("\\%c"), i18n_conditions(getConditions()));
-    res = res.replace(QRegExp("\\%v"), i18n("weather", getVisibility()) + (atol(getVisibility()) ? QString(" ") + i18n(getUD()) : ""));
+    res = res.replace(QRegExp("\\%v"), i18n("weather", getVisibility()) + (atol(getVisibility()) ? QString(" ") + i18n(getUD()) : QString("")));
     return res;
 }
 

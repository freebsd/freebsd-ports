libc++ (unlike libstdc++) doesn't bootleg <locale.h> via <string>:

  src/main.cpp:17:15: error: use of undeclared identifier 'LC_NUMERIC'
      setlocale(LC_NUMERIC, "C"); // for mpv
                ^
  1 error generated.

--- src/main.cpp~
+++ src/main.cpp
@@ -4,6 +4,8 @@
 #include <QLocale>
 #include <QString>
 
+#include <locale.h>
+
 #if defined(Q_OS_WIN)
 #include <windows.h>
 #endif

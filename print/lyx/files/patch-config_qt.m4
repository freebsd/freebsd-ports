--- config/qt.m4	2026-09-07 18:54:34 UTC
+++ config/qt.m4
@@ -402,8 +402,8 @@ EOF1
 QMAKE_PROJECT_DEPTH = 0
 EOF1
 	    $QT_QMAKE $lyx_test_qt_pro -o $lyx_test_qt_mak 1>/dev/null 2>&1
-	    QT_CORE_INCLUDES=`cd $lyx_test_qt_dir; make -s -f $lyx_test_qt_mak INCPATH | sed 's/-I\. //g'`
-	    qt_corelibs=`cd $lyx_test_qt_dir; make -s -f $lyx_test_qt_mak LIBS`
+	    QT_CORE_INCLUDES=`cd $lyx_test_qt_dir; ${MAKE-make} -s -f $lyx_test_qt_mak INCPATH | sed 's/-I\. //g'`
+	    qt_corelibs=`cd $lyx_test_qt_dir; ${MAKE-make} -s -f $lyx_test_qt_mak LIBS`
 	    QT_CORE_LDFLAGS=`echo $qt_corelibs | tr ' ' '\n' | grep -e "^-L" | tr '\n' ' '`
 	    if test -z "$QT_CORE_LDFLAGS"; then
 		QT_CORE_LDFLAGS="-L`$QT_QMAKE -query QT_INSTALL_LIBS`"
@@ -442,8 +442,8 @@ EOF4
 EOF4
 	        fi
 		$QT_QMAKE $lyx_test_qt_pro -o $lyx_test_qt_mak 1>/dev/null 2>&1
-		QT_INCLUDES=`cd $lyx_test_qt_dir; make -s -f $lyx_test_qt_mak INCPATH | sed 's/-I\. //g'`
-		qt_guilibs=`cd $lyx_test_qt_dir; make -s -f $lyx_test_qt_mak LIBS`
+		QT_INCLUDES=`cd $lyx_test_qt_dir; ${MAKE-make} -s -f $lyx_test_qt_mak INCPATH | sed 's/-I\. //g'`
+		qt_guilibs=`cd $lyx_test_qt_dir; ${MAKE-make} -s -f $lyx_test_qt_mak LIBS`
 		QT_LDFLAGS=`echo $qt_guilibs | tr ' ' '\n' | grep -e "^-L" | tr '\n' ' '`
 		if test -z "$QT_LDFLAGS"; then
 		    QT_LDFLAGS="-L`$QT_QMAKE -query QT_INSTALL_LIBS`"
@@ -455,11 +455,11 @@ EOF4
 		if test -z "$QT_LIB"; then
 		    AC_MSG_RESULT(no)
 		else
-		    QT_MISSING=`cd $lyx_test_qt_dir; make -s -f $lyx_test_qt_mak EXPORT_MISSING | sed 's/^ *//'`
+		    QT_MISSING=`cd $lyx_test_qt_dir; ${MAKE-make} -s -f $lyx_test_qt_mak EXPORT_MISSING | sed 's/^ *//'`
 		    if test -n "$QT_MISSING"; then
 			    AC_MSG_ERROR([Qt$qt_major module(s) $QT_MISSING not found.])
 		    fi
-		    QT5_X11_EXTRAS=`cd $lyx_test_qt_dir; make -s -f $lyx_test_qt_mak DEFINES | grep QT_X11EXTRAS_LIB`
+		    QT5_X11_EXTRAS=`cd $lyx_test_qt_dir; ${MAKE-make} -s -f $lyx_test_qt_mak DEFINES | grep QT_X11EXTRAS_LIB`
 		    if test -n "$QT5_X11_EXTRAS"; then
 			QT_LIB="$QT_LIB -lxcb"
 			AC_DEFINE(HAVE_QT5_X11_EXTRAS, 1,

--- aclocal.m4.orig	Thu Dec  1 08:02:22 2005
+++ aclocal.m4	Mon Apr 30 11:35:44 2007
@@ -19,7 +19,7 @@
     esac
     AC_MSG_CHECKING(m4 flags)
     case "${M4FLAGS-unset}" in
-	unset) M4FLAGS=-B10000 ;;
+	unset) M4FLAGS= ;;
     esac
     AC_MSG_RESULT($M4FLAGS)
     AC_SUBST(M4FLAGS)

--- Configure
+++ Configure
@@ -2156,6 +2156,10 @@
     then
       LSOF_CFGF="$LSOF_CFGF -DHASIPv6"
     fi	# }
+    if test -r ${LSOF_INCLUDE}/utmpx.h	# {
+    then
+      LSOF_CFGF="$LSOF_CFGF -DHASUTMPX"
+    fi	# }
     LSOF_DIALECT_DIR=freebsd
     ;;
 
--- lsof.h
+++ lsof.h
@@ -267,10 +267,11 @@
 # if	!defined(LOGINML)
 #  if	defined(HASUTMPX)
 static struct utmpx dummy_utmp;		/* to get login name length */
+#define	LOGINML		sizeof(dummy_utmp.ut_user)
 # else	/* !defined(HASUTMPX) */
 static struct utmp dummy_utmp;		/* to get login name length */
-# endif	/* defined(HASUTMPX) */
 #define	LOGINML		sizeof(dummy_utmp.ut_name)
+# endif	/* defined(HASUTMPX) */
 					/* login name length */
 # endif	/* !defined(LOGINML) */
 

--- extconf.sh.orig	Thu Feb 22 06:01:54 2001
+++ extconf.sh	Sat Mar  3 17:27:35 2001
@@ -1,4 +1,4 @@
-#!/bin/bash --
+#!/bin/sh --
 # extconf.sh
 # configuring pRuby before compilation
 # by pts@fazekas.hu at Wed Feb 21 16:18:26 CET 2001
@@ -25,7 +25,7 @@
 
 show() {
   echo "$@" >&2
-  command "$@"
+  "$@"
 }
 
 [ -f Configuration ] || fatal "file ./Configuration does not exist"
@@ -36,17 +36,17 @@
   exit 3
 fi
 rm -f configed.now
-make confclean
+gmake confclean
 
-type -p make 2>&1 >/dev/null || fatal "not on \$PATH: make"
-type -p bash 2>&1 >/dev/null || fatal "not on \$PATH: bash"
-type -p gcc 2>&1 >/dev/null || fatal "not on \$PATH: gcc"
-type -p rm 2>&1 >/dev/null || fatal "not on \$PATH: rm"
-type -p cp 2>&1 >/dev/null || fatal "not on \$PATH: cp"
-type -p mv 2>&1 >/dev/null || fatal "not on \$PATH: mv"
-type -p cat 2>&1 >/dev/null || fatal "not on \$PATH: cat"
-type -p mkdir 2>&1 >/dev/null || fatal "not on \$PATH: mkdir"
-type -p rmdir 2>&1 >/dev/null || fatal "not on \$PATH: rmdir"
+which -s gmake 2>&1 >/dev/null || fatal "not on \$PATH: gmake"
+which -s sh 2>&1 >/dev/null || fatal "not on \$PATH: sh"
+which -s gcc 2>&1 >/dev/null || fatal "not on \$PATH: gcc"
+which -s rm 2>&1 >/dev/null || fatal "not on \$PATH: rm"
+which -s cp 2>&1 >/dev/null || fatal "not on \$PATH: cp"
+which -s mv 2>&1 >/dev/null || fatal "not on \$PATH: mv"
+which -s cat 2>&1 >/dev/null || fatal "not on \$PATH: cat"
+which -s mkdir 2>&1 >/dev/null || fatal "not on \$PATH: mkdir"
+which -s rmdir 2>&1 >/dev/null || fatal "not on \$PATH: rmdir"
 [ -n "$RUBY" ] || fatal "please set RUBY= in ./Configuration"
 [ -n "$PHP4_SRC" ] || fatal "set PHP4_SRC= in ./Configuration"
 [ -f "$PHP4_SRC/README.CVS-RULES" ] || fatal "PHP4_SRC= does not contain PHP4??"
@@ -84,8 +84,8 @@
 	# RB_DLDFLAGS='\''$(DLDFLAGS)'\''
 '
 unset MAKELEVEL
-make -f rtmp/Makefile getflags | $RUBY -pe '$_.sub!(/^#\s*/,"")' >rbwhere.mk || fexit "$?"
-make -f rtmp/Makefile getflagsh| $RUBY -pe '$_.sub!(/^#\s*/,"")' >rbwhere.sd || fexit "$?"
+gmake -f rtmp/Makefile getflags | $RUBY -pe '$_.sub!(/^#\s*/,"")' >rbwhere.mk || fexit "$?"
+gmake -f rtmp/Makefile getflagsh| $RUBY -pe '$_.sub!(/^#\s*/,"")' >rbwhere.sd || fexit "$?"
 # less rtmp/Makefile
 rm -f rtmp/Makefile
 rmdir rtmp
@@ -135,13 +135,13 @@
 # No we examine output of phpinfo.out
 #
 [ -f phpinfo.out ] || fatal "You should have created phpinfo.out. See docs for details."
-/tmp/ruby/bin/ruby -wne'print "PI_#{$1.upcase.tr %q[ -().],%q[_____]}=\x27#{$2}\x27\n" if $_=~/\A(?:<[^>]+>)+(configuration file .php.ini. path|extension_dir|thread safety|ZEND_DEBUG)(?:<[^>]+>)+([^<]*)/i' <phpinfo.out  >phpinfo.sd || fatal "phpinfo.out bad??"
-/tmp/ruby/bin/ruby -wne'print "PI_#{$1.upcase.tr %q[ -().],%q[_____]}=#{$2}\n"         if $_=~/\A(?:<[^>]+>)+(configuration file .php.ini. path|extension_dir|thread safety|ZEND_DEBUG)(?:<[^>]+>)+([^<]*)/i' <phpinfo.out >>rbwhere.mk || fatal "phpinfo.out bad??"
+$RUBY -wne'print "PI_#{$1.upcase.tr %q[ -().],%q[_____]}=\x27#{$2}\x27\n" if $_=~/\A(?:<[^>]+>)+(configuration file .php.ini. path|extension_dir|thread safety|ZEND_DEBUG)(?:<[^>]+>)+([^<]*)/i' <phpinfo.out  >phpinfo.sd || fatal "phpinfo.out bad??"
+$RUBY -wne'print "PI_#{$1.upcase.tr %q[ -().],%q[_____]}=#{$2}\n"         if $_=~/\A(?:<[^>]+>)+(configuration file .php.ini. path|extension_dir|thread safety|ZEND_DEBUG)(?:<[^>]+>)+([^<]*)/i' <phpinfo.out >>rbwhere.mk || fatal "phpinfo.out bad??"
 . phpinfo.sd
 [ -n "$PI_EXTENSION_DIR" ] || fatal "cannot get \`extension_dir' from phpinfo.out"
 [ -n "$PI_CONFIGURATION_FILE__PHP_INI__PATH" ] || fatal "cannot get path for php.ini from phpinfo.out"
-[ -f "$PI_CONFIGURATION_FILE__PHP_INI__PATH/php.ini" ] || fatal "php.ini isn't there"
-[ -d "$PI_EXTENSION_DIR" ] || fatal "PHP extension_dir ($PI_EXTENSION_DIR) not exists"
+#[ -f "$PI_CONFIGURATION_FILE__PHP_INI__PATH/php.ini" ] || fatal "php.ini isn't there"
+#[ -d "$PI_EXTENSION_DIR" ] || fatal "PHP extension_dir ($PI_EXTENSION_DIR) not exists"
 
 rm -rf phpfake # dangerous??
 echo "Creating phpfake/*"
@@ -149,7 +149,7 @@
 for N in `cd "$PHP4_SRC"; ls *.h */*.h ext/standard/*.h build/*.mk`; do
   if [ ! -f "$PHP4_SRC/$N.in" ]; then
     [ "${N%/*}" != "$N" ] && mkdir -p "phpfake/${N%/*}"
-    cp -fa "$PHP4_SRC/$N" "phpfake/$N" || fexit "$?"
+    cp -fRPp "$PHP4_SRC/$N" "phpfake/$N" || fexit "$?"
   fi
 done
 rm -f phpfake/php_config.h
@@ -161,7 +161,7 @@
     php_config.h.in build/fastgen.sh main/internal_functions.c.in Zend/Makefile.in'
   for N in $FILES; do
     [ "${N%/*}" != "$N" ] && mkdir -p "phpfake/${N%/*}"
-    cp -fa "$PHP4_SRC/$N" "phpfake/$N" || fexit "$?"
+    cp -fRPp "$PHP4_SRC/$N" "phpfake/$N" || fexit "$?"
   done
   COFLAGS=
   if [ "PI_THREAD_SAFETY" != "enabled" ]; then
@@ -186,12 +186,12 @@
 else
   echo "PHP4 already configured."
   FILES='README.CVS-RULES install-sh
-    build/shtool build/fastgen.sh build-defs.h
+    build/shtool build/fastgen.sh main/build-defs.h
     pear/phpize pear/php-config libtool
-    php_config.h php_version.h config_vars.mk'
+    main/php_config.h main/php_version.h config_vars.mk'
   for N in $FILES; do
     [ "${N%/*}" != "$N" ] && mkdir -p "phpfake/${N%/*}"
-    cp -fa "$PHP4_SRC/$N" "phpfake/$N" || fexit "$?"
+    cp -fRPp "$PHP4_SRC/$N" "phpfake/$N" || fexit "$?"
   done
 fi
 

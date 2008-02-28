--- lib/Script/procmail.php.orig	2007-08-21 17:51:56.000000000 -0800
+++ lib/Script/procmail.php	2007-12-04 00:37:57.000000000 -0900
@@ -434,9 +434,15 @@
             $this->_action[] = '{';
             foreach ($params['action-value']['addresses'] as $address) {
                 if (!empty($address)) {
-                    $this->_action[] = '  FILEDATE=`test -f \'.vacation.' . $address . '\' && '
-                        . 'ls -lcn --time-style=+%s \'.vacation.' . $address . '\' | '
-                        . 'awk \'{ print $6 + (' . $days * 86400 . ') }\'`';
+/***** This bit does not work with FreeBSD
+*                    $this->_action[] = '  FILEDATE=`test -f \'.vacation.' . $address . '\' && '
+*                        . 'ls -lcn --time-style=+%s \'.vacation.' . $address . '\' | '
+*                        . 'awk \'{ print $6 + (' . $days * 86400 . ') }\'`';
+*/
+                    $this->_action[] = '  FDATE=`ls -lcnT \'.vacation.' . $address
+                                       . '\' 2> /dev/null | awk \'{ print $6, $7, $8, $9; }\'`';
+                    $this->_action[] = '  FILEDATE=`date -j -f "%b %d %H:%M:%S %Y" "$FDATE" +%s '
+                                       . ' | awk \'{ print $1 + (' . $days * 86400 . ') }\'`';
                     $this->_action[] = '  DATE=`date +%s`';
                     $this->_action[] = '  DUMMY=`test -f \'.vacation.' . $address . '\' && '
                         . 'test $FILEDATE -le $DATE && '

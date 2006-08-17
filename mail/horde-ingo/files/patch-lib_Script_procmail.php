--- lib/Script/procmail.php.orig	Tue Jan 31 20:00:25 2006
+++ lib/Script/procmail.php	Thu Aug 17 14:52:45 2006
@@ -427,9 +427,16 @@
             $this->_action[] = '{';
             foreach ($params['action-value']['addresses'] as $address) {
                 if (!empty($address)) {
-                    $this->_action[] = '  FILEDATE=`ls -lcn --time-style=+%s \'.vacation.' . $address
-                                       . '\' | awk \'{ print $6 + ('
-                                       . $days * 86400 . ') }\'`';
+/***** This bit does not work with FreeBSD.
+ *                   $this->_action[] = '  FILEDATE=`ls -lcn --time-style=+%s \'.vacation.' . $address
+ *                                      . '\' | awk \'{ print $6 + ('
+ *                                      . $days * 86400 . ') }\'`';
+ *
+ */
+                    $this->_action[] = '  FDATE=`ls -lcnT \'.vacation.' . $address
+                                       . '\' 2> /dev/null | awk \'{ print $6, $7, $8, $9; }\'`';
+                    $this->_action[] = '  FILEDATE=`date -j -f "%b %d %H:%M:%S %Y" "$FDATE" +%s '
+                                       . ' | awk \'{ print $1 + (' . $days * 86400 . ') }\'`';
                     $this->_action[] = '  DATE=`date +%s`';
                     $this->_action[] = '  DUMMY=`test $FILEDATE -le $DATE'
                                        .' && rm \'.vacation.' . $address .'\'`';

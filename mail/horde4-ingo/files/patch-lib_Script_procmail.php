--- lib/Script/procmail.php.orig	2008-05-05 09:22:21.000000000 -0800
+++ lib/Script/procmail.php	2008-06-29 16:56:12.000000000 -0800
@@ -470,9 +470,6 @@
             $this->_action[] = '{';
             foreach ($params['action-value']['addresses'] as $address) {
                 if (!empty($address)) {
-                    $this->_action[] = '  FILEDATE=`test -f ${VACATION_DIR:-.}/\'.vacation.' . $address . '\' && '
-                        . $this->_params['ls'] . ' -lcn --time-style=+%s ${VACATION_DIR:-.}/\'.vacation.' . $address . '\' | '
-                        . 'awk \'{ print $6 + (' . $days * 86400 . ') }\'`';
                     $this->_action[] = '  DATE=`' . $this->_params['date'] . ' +%s`';
                     $this->_action[] = '  DUMMY=`test -f ${VACATION_DIR:-.}/\'.vacation.' . $address . '\' && '
                         . 'test $FILEDATE -le $DATE && '

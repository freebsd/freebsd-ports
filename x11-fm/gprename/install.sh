echo "#!/bin/sh" >/usr/local/bin/gprename
echo "index=\`expr index \"\$1\" /\`;" >> /usr/local/bin/gprename
echo "if [ \$index != 1 ]">> /usr/local/bin/gprename
echo "then">> /usr/local/bin/gprename
echo "        dir=\`pwd\`/\$1;">> /usr/local/bin/gprename
echo "else">> /usr/local/bin/gprename
echo "        dir=\"\$1\";">> /usr/local/bin/gprename
echo "fi">> /usr/local/bin/gprename
echo "perl $INSTALLDIR/gprename.pl $INSTALLDIR \$dir &" >>/usr/local/bin/gprename

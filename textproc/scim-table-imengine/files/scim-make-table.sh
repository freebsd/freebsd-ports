#!/bin/sh

cat <<EOF
************************************************************
**                        N O T E                         **
************************************************************

This is NOT a working scim-make-table. Due to the limitation
on your system, scim-make-table cannot be compiled. So you
cannot build binary im tables on this system.

However, the scim-tables im engine is available, i.e. You
still have the chance to use table-based input methods for
scim. You can let someone build a tgz package for
{zh,ja,ko}-scim-tables port on a 5.x system and then install
it on your system.
EOF
exit 2

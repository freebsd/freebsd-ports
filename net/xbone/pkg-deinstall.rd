#!/bin/sh
if [ -z $2 ]; then
  exit 0
fi
if [ $2 != "POST-DEINSTALL" ]; then
  echo "!!! This script is for post-deinstallation only."; \
  exit 0
fi
echo "==> Post-deinstallation cleanup:"
if [ -d /etc/xbone ]; then
  /usr/bin/dialog --yesno "/etc/xbone found. Do you want to DELETE it?\
                           Warning: <YES> would DELETE ALL XBONE CONFIG/STATE\
			   files and ALL CERTIFICATES." 8 50 && 
  rm -rf /etc/xbone || echo "    - /etc/xbone is not deleted."
fi
if [ -d /usr/local/xbone ]; then
  /usr/bin/dialog --yesno "Do you want to DELETE all remaining XBone files\
                           under /usr/local/xbone?" 8 50 &&
  rm -rf /usr/local/xbone || echo "    - /usr/local/xbone not deleted."
fi


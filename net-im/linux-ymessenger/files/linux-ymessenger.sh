#!/bin/sh
if [ -w $HOME/.ymessenger/preferences ]; then
  /usr/bin/grep -q '^PrimaryIdentity $' $HOME/.ymessenger/preferences&&/usr/bin/sed -i '' -e '/^PrimaryIdentity $/s/$/ ""/' $HOME/.ymessenger/preferences
fi
export LD_LIBRARY_PATH=%%PREFIX%%/lib/linux-ymessenger
cd %%PREFIX%%/libexec/linux-ymessenger
./ymessenger.bin $*

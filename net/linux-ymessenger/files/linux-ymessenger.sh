#!/bin/sh
export LD_LIBRARY_PATH=%%PREFIX%%/lib/linux-ymessenger
cd %%PREFIX%%/libexec/linux-ymessenger
./ymessenger.bin $*

#!/bin/sh
cd %%PREFIX%%/danamics
exec javavm -classpath DaNAMiCS.jar:swing.jar:$CLASSPATH DaNAMiCS.DFrame

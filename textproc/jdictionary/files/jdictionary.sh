#!/bin/sh
cd %%PREFIX%%/share/java/classes/jdictionary
exec %%LOCALBASE%%/bin/javavm -jar %%PREFIX%%/share/java/classes/jdictionary/jdictionary.jar

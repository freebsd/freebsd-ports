#!/bin/sh

if [ -z "${CLASSPATH}" ]
then
	CLASSPATH=/usr/local/share/java/classes/jfc-1.1.1/swingall.jar:/usr/local/share/java/classes/furi/furi.jar:/usr/local/jre1.1.8/lib:/usr/local/jdk1.1.8/lib/classes.zip
else
	CLASSPATH="${CLASSPATH}:/usr/local/share/java/classes/jfc-1.1.1/swingall.jar:/usr/local/share/java/classes/furi/furi.jar:/usr/local/jre1.1.8/lib:/usr/local/jdk1.1.8/lib/classes.zip"
fi

exec env CLASSPATH="${CLASSPATH}" /usr/local/bin/javavm furi.f &

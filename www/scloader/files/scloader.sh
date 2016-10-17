#! /bin/sh

exec "%%JAVA%%" -mx512m -jar "%%JAVAJARDIR%%/scloader.jar" "$@"

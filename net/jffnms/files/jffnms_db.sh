#!/bin/sh
# Created by Sergey Akifyev <asa@gascom.ru>
#

{
	echo "CREATE DATABASE jffnms;
		GRANT ALL PRIVILEGES ON jffnms.* TO jffnms@localhost
		IDENTIFIED BY 'jffnms';
		FLUSH PRIVILEGES;"
	cat %JFFNMSDIR%/docs/%JFFNMS%.mysql
} | mysql ${*}

# New ports collection makefile for:    apache HTTPD
# Version required:     1.3
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 ache@nagual.pp.ru
#
# $Id: Makefile,v 1.54 1998/06/09 19:49:59 ache Exp $
#

DISTNAME=       apache_1.3.0
PKGNAME=        apache-1.3.0
CATEGORIES=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/

#PATCH_SITES=    ftp://www.apache.org/apache/dist/patches/apply_to_1.3.0/

MAINTAINER=     ache@freebsd.org

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= \
		 --logfiledir=/var/log \
		 --runtimedir=/var/run \
		 --datadir=${PREFIX}/www \
		 --proxycachedir=${PREFIX}/www/proxy \
		 --libexecdir=${PREFIX}/libexec/apache \
		 --disable-rule=STATUS \
		 --enable-shared=remain \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --disable-module=auth_dbm

CONFIGURE_ENV= \
OPTIM='-DBUFFERED_LOGS -DHARD_SERVER_LIMIT=512 \
-DDOCUMENT_LOCATION=\\"'${PREFIX}'/www/data/\\" \
-DDEFAULT_PATH=\\"/bin:/usr/bin:'${PREFIX}'/bin\\"'

MAN1=   ab.1 apachectl.1 dbmmanage.1 htdigest.1 htpasswd.1
MAN8=   apxs.8 httpd.8 logresolve.8 rotatelogs.8

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		echo "[ -x /usr/local/sbin/httpd ] && /usr/local/sbin/httpd && echo -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>

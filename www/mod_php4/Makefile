# New ports collection makefile for:	apache HTTPD / php 2.0b12
# Version required:	1.2.1 / 2.0b12
# Date created:		Wed Sep  3 18:28:20 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id$
#

DISTNAME=       apache_1.2.1
CATEGORIES=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/ \
		ftp://ftp.nerosworld.com/pub/php/dist/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/www/php \
		ftp://ftpza.co.za/pub/mirrors/php/
DISTFILES=	apache_1.2.1.tar.gz \
                php-2.0b12.tar.gz

MAINTAINER=     andreas@FreeBSD.ORG

NO_PACKAGE=	"Too many questions"
IS_INTERACTIVE=	yes
BROKEN=		"Am working on it..."

#
# Currently we support two db's: msql and mysql
#
.if !defined(PHP_DBTYPE)
pre-fetch:
	@echo
	@echo "You must set variable PHP_DBTYPE to msql or mysql by typing"
	@echo "make PHP_DBTYPE=[ msql | mysql ]"
	@false

.elif defined(PHP_DBTYPE)
.if ${PHP_DBTYPE} == msql
BUILD_DEPENDS=	msql:${PORTSDIR}/databases/msql
PATCHDIR=	${.CURDIR}/patches.msql

.elif ${PHP_DBTYPE} == mysql
BUILD_DEPENDS=	mysql:${PORTSDIR}/databases/mysql
PATCHDIR=	${.CURDIR}/patches.mysql
.endif
.endif

# Set it for local-supplied patch, f.e.
VERS_ID = php-2.0b12/andreas

.if defined(VERS_ID)
post-patch:
	@cd ${WRKSRC}/src && \
	mv Configuration Configuration.old && \
	sed 's;^#*OPTIM=.*;OPTIM= -DSERVER_SUBVERSION=\\"${VERS_ID}\\";' \
	< Configuration.old > Configuration
.endif


pre-configure:
	echo "Don\'t forget to add ${PREFIX}/include/gd to additional path !!!"
	( cd ${WRKDIR}/php-2.0b12; ./install )
	( cd ${WRKDIR}/php-2.0b12/src; make )
	( cd ${WRKDIR}/php-2.0b12/src \
	&& cp mod_php.c mod_php.h libphp.a ../../apache_1.2.1/src )
	( cd ${WRKDIR}/apache_1.2.1/src \
	&& echo "Module php_module mod_php.o" \
	>> Configuration \
	&& echo "EXTRA_LIBS=-lmd libphp.a -L/usr/local/lib -lmsql -lgd -lm" \
	>> Configuration )

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		echo "[ -x /usr/local/sbin/httpd ] && /usr/local/sbin/httpd && echo -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	echo "AddType application/x-httpd-php .phtml" \
		> ${PREFIX}/etc/apache/srm.conf.php
	echo "Don't forget to enable php support in \
		${PREFIX}/etc/apache/srm.conf"
	echo "See ${PREFIX}/etc/apache/srm.conf.php"

.include <bsd.port.mk>

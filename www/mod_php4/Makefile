# New ports collection makefile for:	apache HTTPD / php 2.0.1
# Version required:	1.2.5 / 2.0.1
# Date created:		Wed Sep  3 18:28:20 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.42 1997/10/04 14:52:58 andreas Exp $
#

DISTNAME=       apache_1.2.5
PKGNAME=	apache-php-1.2.5
CATEGORIES=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/ \
		ftp://ftp.nerosworld.com/pub/php/dist/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/www/php/ \
		ftp://ftpza.co.za/pub/mirrors/php/
DISTFILES=	apache_1.2.5.tar.gz php-2.0.1.tar.gz

MAINTAINER=     andreas@FreeBSD.ORG

NO_PACKAGE=	"Too many questions"

#
# Currently we support two db's: msql and mysql
# When running in batch mode default to mysql support, because it's
# a free and very popular database !
#
.if defined(BATCH)
PHP_DBTYPE=mysql
.endif

.if !defined(PHP_DBTYPE)
pre-fetch:
	@ ${ECHO}
	@ ${ECHO} "You must set variable PHP_DBTYPE to msql or mysql by typing"
	@ ${ECHO} "make PHP_DBTYPE=[ msql | mysql ]"
	@ ${FALSE}

.elif defined(PHP_DBTYPE)
.if ${PHP_DBTYPE} == msql
BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd \
		msql:${PORTSDIR}/databases/msql
PATCHDIR=	${.CURDIR}/patches.msql

.elif ${PHP_DBTYPE} == mysql
BUILD_DEPENDS=	${PREFIX}/lib/libgd.a:${PORTSDIR}/graphics/gd \
		mysql:${PORTSDIR}/databases/mysql
PATCHDIR=	${.CURDIR}/patches.mysql
.endif
.endif

# Set it for local-supplied patch, f.e.
VERS_ID = php-2.0.1/andreas

.if defined(VERS_ID)
post-patch:
	@ cd ${WRKSRC}/src && \
	${MV}  Configuration Configuration.old && \
	${SED} 's;^#*OPTIM=.*;OPTIM= -DSERVER_SUBVERSION=\\"${VERS_ID}\\";' \
	< Configuration.old > Configuration
.endif

pre-configure:
.if !defined(PHP_DBTYPE)
	@ ${ECHO}
	@ ${ECHO} "You must set variable PHP_DBTYPE to msql or mysql by typing"
	@ ${ECHO} "make PHP_DBTYPE=[ msql | mysql ]"
	@ ${FALSE}
.else
	( cd ${WRKDIR}/php-2.0.1; ${SED} "s#@@PREFIX@@#${PREFIX}#" < ${FILESDIR}/install.patch | patch)
	( cd ${WRKDIR}/php-2.0.1; ./install )
	( cd ${WRKDIR}/php-2.0.1/src; make )
	( cd ${WRKDIR}/php-2.0.1/src \
	&& ${CP} mod_php.c mod_php.h libphp.a ../../apache_1.2.5/src )
	( cd ${WRKDIR}/apache_1.2.5/src \
	&& ${ECHO} "Module php_module mod_php.o" \
	>> Configuration )
.if ${PHP_DBTYPE} == msql
	( cd ${WRKDIR}/apache_1.2.5/src \
	&& ${ECHO} "EXTRA_LIBS=-lmd libphp.a -L${PREFIX}/lib -lmsql -lgd -lm" \
	>> Configuration )
.else
	( cd ${WRKDIR}/apache_1.2.5/src \
	&& ${ECHO} "EXTRA_LIBS=-lmd libphp.a -L${PREFIX}/lib/mysql -lmysqlclient -L${PREFIX}/lib -lgd -lm" \
	>> Configuration )
.endif
.endif

post-install:
	@ if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/httpd ] && ${PREFIX}/sbin/httpd && ${ECHO} -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	${ECHO} "AddType application/x-httpd-php .phtml" \
		> ${PREFIX}/etc/apache/srm.conf.php
	@ ${ECHO} "Don't forget to enable php support in \
		${PREFIX}/etc/apache/srm.conf"
	@ ${ECHO} "See ${PREFIX}/etc/apache/srm.conf.php"

.include <bsd.port.mk>

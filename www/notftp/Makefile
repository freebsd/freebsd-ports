# New ports collection makefile for:	NotFTP
# Date created:		3 July 2002
# Whom:			Ryan Grove <ryan@wonko.com>
#
# $FreeBSD$
#

PORTNAME=	notftp
PORTVERSION=	1.3.1
CATEGORIES=	www ftp
MASTER_SITES=	http://wonko.com/notftp/files/

MAINTAINER=	ryan@wonko.com
COMMENT=	An easy to use Web to FTP gateway written in PHP

.if exists(${LOCALBASE}/include/apache2/os.h)
WITH_APACHE2=	yes
.endif

.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache2/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

PREFIX=		${LOCALBASE}
WEBOWN?=	www
WEBGRP?=	www
APACHEDIR=	${PREFIX}/www/data
INSTALLDIR=	${APACHEDIR}/notftp
NO_BUILD=	yes

PLIST_SUB+=	INSTALLDIR=${INSTALLDIR:S,^${PREFIX}/,,}

do-install:
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WEBOWN}:${WEBGRP} ${INSTALLDIR}
	${FIND} ${INSTALLDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}

.include <bsd.port.mk>

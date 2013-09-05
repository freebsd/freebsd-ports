# Created by: Ryan Grove <ryan@wonko.com>
# $FreeBSD$

PORTNAME=	notftp
PORTVERSION=	1.3.1
CATEGORIES=	www ftp
MASTER_SITES=	http://wonko.com/notftp/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An easy to use Web to FTP gateway written in PHP

DEPRECATED=	distfile unfetchable
EXPIRATION_DATE=2014-01-01

USE_PHP=	yes

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

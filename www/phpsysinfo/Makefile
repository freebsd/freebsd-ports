# Created by: Bob Bomar <bob@fly.homeunix.org>
# $FreeBSD$

PORTNAME=	phpsysinfo
PORTVERSION=	3.0.10
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	walt@relnor.com
COMMENT=	PHP script for displaying system information

LICENSE=	GPLv2

USE_PHP=	dom pcre xml simplexml mbstring
WANT_PHP_WEB=	yes

LATEST_LINK=	phpsysinfo-dev

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	${CHMOD} -R ${BINMODE} ${STAGEDIR}${WWWDIR}
	${FIND} ${STAGEDIR}${WWWDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}

.include <bsd.port.mk>

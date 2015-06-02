# Created by: Bob Bomar <bob@fly.homeunix.org>
# $FreeBSD$

PORTNAME=	phpsysinfo
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	GHL

MAINTAINER=	walt@relnor.com
COMMENT=	PHP script for displaying system information

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	phpsysinfo
GH_TAGNAME=	v3.2.0
GH_COMMIT=	5a2d026

USES=		shebangfix
SHEBANG_FILES=	tools/check.sh
NO_BUILD=	yes
USE_PHP=	dom pcre xml simplexml mbstring
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message
PLIST_SUB=	NOBINMODE="${NOBINMODE}" WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}; ${FIND} . \! -name .travis.yml \
		| ${CPIO} -pdm ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

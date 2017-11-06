# Created by: Bob Bomar <bob@fly.homeunix.org>
# $FreeBSD$

PORTNAME=	phpsysinfo
PORTVERSION=	3.2.8
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	tremere@cainites.net
COMMENT=	PHP script for displaying system information

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes

USES=		php:web shebangfix
SHEBANG_FILES=	tools/check.sh
USE_PHP=	dom pcre xml simplexml mbstring
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message
PLIST_SUB=	NOBINMODE="${NOBINMODE}" WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${FIND} . \! -name .travis.yml \
		| ${CPIO} -pdm ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

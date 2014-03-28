# Created by: Francisco Cabrita <include@npf.pt.freebsd.org>
# $FreeBSD$

PORTNAME=	joomla
PORTVERSION=	2.5.19
CATEGORIES=	www
PKGNAMESUFFIX=	2

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Dynamic web content management system (CMS)

LICENSE=	GPLv2

GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}-cms
GH_COMMIT=	4752848

NO_BUILD=	yes

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
php_OLD_CMD=	C:\\\xampp\\\php\\\.\\\php.exe

REINPLACE_ARGS=	-i '' -e 's,${php_OLD_CMD},${LOCALBASE}/bin/php,g'
REINPLACE_FILES=	tests/unit/phpunit.php tests/system/phpunit.php

SUB_FILES=	pkg-message

USE_GITHUB=	yes
USE_MYSQL=	yes
USE_PHP=	gd json mbstring mysql mysqli pcre pdf session simplexml xml zip zlib

WANT_PHP_WEB=	yes
WWWDIR=	${PREFIX}/www/${PORTNAME}${PORTVERSION:R:R}

pre-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} ${REINPLACE_FILES})

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${WWWDIR}/{} \;)
	@(cd ${WRKSRC} && \
		${FIND} . \! -type d -and \! \( -name .gitignore -or -name .travis.yml \
			-or -name LICENSE.txt -or -name build.xml \) \
			-exec ${INSTALL_DATA} {} ${STAGEDIR}${WWWDIR}/{} \;)

.include <bsd.port.mk>

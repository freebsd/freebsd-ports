# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	typo3
PORTVERSION=	4.7.18
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TYPO3%20Source%20and%20Dummy/TYPO3%20${PORTVERSION}
PKGNAMESUFFIX=	${TYPO3RELEASE}

MAINTAINER=	freebsd-ports@charlieroot.de
COMMENT=	The typo3 content management system

LICENSE=	GPLv2

PORTSCOUT=	limit:^4\.7\.

NO_BUILD=	yes
USE_PHP=	ctype filter json mysql pcre session xml
WANT_PHP_WEB=	yes

TYPO3WWW=	www
TYPO3RELEASE=	47
TYPO3SITE=	${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}
TYPO3PKG=	${PORTNAME}-${PORTVERSION}
TYPO3SRC=	${PORTNAME}_src-${PORTVERSION}
TYPO3DUMMY=	dummy-${PORTVERSION}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

DISTFILES+=	${TYPO3SRC}${EXTRACT_SUFX} ${TYPO3DUMMY}${EXTRACT_SUFX}

OPTIONS_DEFINE=	CURL GD IMAGICK MBSTRING ZLIB
GD_DESC=	GDlib/freetype support
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
MBSTRING_DESC=	${MULTIBYTE_DESC}

CURL_USE=	PHP=curl
GD_USE=		PHP=gd
MBSTRING_USE=	PHP=mbstring
ZLIB_USE=	PHP=zlib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif
.endif

pre-install:
	${MV} ${WRKDIR}/${TYPO3DUMMY}/typo3conf/localconf.php \
		${WRKDIR}/${TYPO3DUMMY}/typo3conf/localconf.php.dist

do-install:
	${CP} -R ${WRKDIR}/${TYPO3DUMMY}/ ${STAGEDIR}${PREFIX}/${TYPO3SITE}
	${CP} -R ${WRKDIR}/${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3WWW}
	${RM} ${STAGEDIR}${PREFIX}/${TYPO3SITE}/typo3_src && \
		${LN} -s ../${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3SITE}/typo3_src

.include <bsd.port.mk>

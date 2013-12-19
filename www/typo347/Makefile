# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	typo3
PORTVERSION=	4.7.17
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

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

DISTFILES+=	${TYPO3SRC}${EXTRACT_SUFX} ${TYPO3DUMMY}${EXTRACT_SUFX}

OPTIONS_DEFINE=	CURL GD IMAGICK MBSTRING ZLIB
GD_DESC=	GDlib/freetype support
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
MBSTRING_DESC=	${MULTIBYTE_DESC}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
USE_PHP+=	curl
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif
.endif

.if ${PORT_OPTIONS:MMBSTRING}
USE_PHP+=	mbstring
.endif

.if ${PORT_OPTIONS:MZLIB}
USE_PHP+=	zlib
.endif

pre-install:
	${MV} ${WRKDIR}/${TYPO3DUMMY}/typo3conf/localconf.php \
		${WRKDIR}/${TYPO3DUMMY}/typo3conf/localconf.php.dist

do-install:
	${CP} -R ${WRKDIR}/${TYPO3DUMMY}/ ${PREFIX}/${TYPO3SITE}
	${CP} -R ${WRKDIR}/${TYPO3SRC} ${PREFIX}/${TYPO3WWW}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPO3SITE}
	${RM} ${PREFIX}/${TYPO3SITE}/typo3_src && \
		cd ${PREFIX}/${TYPO3SITE} && \
		${LN} -s ../${TYPO3SRC} typo3_src
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPO3WWW}/${TYPO3SRC}

.include <bsd.port.mk>

# Created by: Helmut Ritter <freebsd-ports@charlieroot.de>
# $FreeBSD$

PORTNAME=	typo3
PORTVERSION=	6.2.1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TYPO3%20Source%20and%20Dummy/TYPO3%20${PORTVERSION}

MAINTAINER=	freebsd-ports@charlieroot.de
COMMENT=	The typo3 content management system

LICENSE=	GPLv2

PORTSCOUT=	limit:^6\.2\.

NO_BUILD=	yes
USE_PHP=	ctype filter json mysqli pcre session xml
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=52

TYPO3WWW=	www
TYPO3RELEASE=	LTS
TYPO3SITE=	${TYPO3WWW}/${PORTNAME}
TYPO3PKG=	${PORTNAME}-${PORTVERSION}
TYPO3SRC=	${PORTNAME}_src-${PORTVERSION}

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

DISTFILES+=	${TYPO3SRC}${EXTRACT_SUFX}

OPTIONS_DEFINE=	APC CURL GD IMAGICK MBSTRING MYSQL ZLIB
APC_DESC=	Alternative PHP Cache
GD_DESC=	GDlib/freetype support
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
MBSTRING_DESC=	${MULTIBYTE_DESC}
MYSQL_DESC=	Install MySQL Server

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPC}
USE_PHP+=	apc
.endif

.if ${PORT_OPTIONS:MCURL}
USE_PHP+=	curl
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif
.endif

.if ${PORT_OPTIONS:MMBSTRING}
USE_PHP+=	mbstring
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	server
IGNORE_WITH_MYSQL=	50
.endif

.if ${PORT_OPTIONS:MZLIB}
USE_PHP+=	zlib
.endif

#pre-install:
#	@if [ -f ${WRKDIR}/${TYPO3DUMMY}/typo3conf/LocalConfiguration.php ]; then \
#		${MV} ${WRKDIR}/${TYPO3DUMMY}/typo3conf/LocalConfiguration.php \
#			${WRKDIR}/${TYPO3DUMMY}/typo3conf/LocalConfiguration.php.dist; \
#	fi

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}
	${CP} -R ${WRKDIR}/${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/
	${LN} -fs ../${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/typo3_src
	${LN} -fs typo3_src/index.php ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/index.php
	${LN} -fs typo3_src/typo3 ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/typo3
	${CP} ${WRKDIR}/${TYPO3SRC}/_.htaccess ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/.htaccess

.include <bsd.port.mk>

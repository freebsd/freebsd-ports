# Created by: Helmut Ritter <freebsd-ports@charlieroot.de>
# $FreeBSD$

PORTNAME=	typo3
PORTVERSION=	${PORT_V_MAJOR}.${PORT_V_MINOR}.${PORT_V_PATCH}
CATEGORIES=	www
MASTER_SITES=	https://typo3.azureedge.net/typo3/${PORTVERSION}/
PKGNAMESUFFIX=	-${PORT_V_MAJOR}${PHP_PKGNAMESUFFIX}

MAINTAINER=	freebsd-ports@charlieroot.de
COMMENT=	Typo3 content management system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

IGNORE_WITH_PHP=	56

PORTSCOUT=	limit:^${PORT_V_MAJOR}\.${PORT_V_MINOR}\.

USES=		cpe php:web,flavors shebangfix
SHEBANG_GLOB=	*.sh *.php
NO_BUILD=	yes
NO_ARCH=	yes
USE_PHP=	ctype fileinfo filter hash json mysqli openssl pcre session simplexml xml zip
WRKSRC=		${WRKDIR}/${TYPO3SRC}

PORT_V_MAJOR=	8
PORT_V_MINOR=	7
PORT_V_PATCH=	22

TYPO3WWW=	www
TYPO3SRC=	${PORTNAME}_src-${PORTVERSION}
TYPO3DIR=	${PORTNAME}-${PORT_V_MAJOR}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}

SUB_FILES=	pkg-message
SUB_LIST+=	PREFIX=${PREFIX} \
		TYPO3WWW=${TYPO3WWW} \
		TYPO3DIR=${TYPO3DIR}

DISTFILES+=	${TYPO3SRC}${EXTRACT_SUFX}

OPTIONS_DEFINE=	CURL GD GMP IMAGICK MBSTRING MYSQL ZLIB
OPTIONS_DEFAULT=
GD_DESC=	GDlib/freetype support
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
MBSTRING_DESC=	${MULTIBYTE_DESC}
MYSQL_DESC=	Install MySQL Server

CURL_USE=	PHP=curl
GD_USE=		PHP=gd
GMP_USE=	PHP=gmp
MBSTRING_USE=	PHP=mbstring
MYSQL_USE=	MYSQL=server
ZLIB_USE=	PHP=zlib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	convert:graphics/ImageMagick6
.else
RUN_DEPENDS+=	convert:graphics/ImageMagick6-nox11
.endif
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}
	${CP} -R ${WRKDIR}/${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/
	${LN} -fs ../${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}/typo3_src
	${LN} -fs typo3_src/index.php ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}/index.php
	${LN} -fs typo3_src/typo3 ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}/typo3
	${CP} ${WRKDIR}/${TYPO3SRC}/_.htaccess ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}/.htaccess

post-install:
	@cd ${STAGEDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) -path "${TYPO3WWW}/${TYPO3DIR}/*" | \
		${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) -path "${TYPO3WWW}/${TYPO3SRC}/*" | \
		${SORT} >> ${TMPPLIST}

	@${ECHO} "@dir ${TYPO3WWW}/${TYPO3SRC}/vendor/doctrine/common/lib/vendor/doctrine-build-common" >> ${TMPPLIST}
	@${ECHO} "@dir ${TYPO3WWW}/${TYPO3SRC}/vendor/doctrine/dbal/lib/vendor/Symfony/Component/Console" >> ${TMPPLIST}
	@${ECHO} "@dir ${TYPO3WWW}/${TYPO3SRC}/vendor/doctrine/dbal/lib/vendor/doctrine-build-common" >> ${TMPPLIST}
	@${ECHO} "@dir ${TYPO3WWW}/${TYPO3SRC}/vendor/doctrine/dbal/lib/vendor/doctrine-common" >> ${TMPPLIST}

.include <bsd.port.mk>

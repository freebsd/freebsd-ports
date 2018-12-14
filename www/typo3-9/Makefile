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

IGNORE_WITH_PHP=56 71

USES=		cpe php:web,flavors shebangfix
USE_PHP=	ctype dom fileinfo filter hash intl json openssl pcre session simplexml \
		spl tokenizer xml zip

WRKSRC=		${WRKDIR}/${TYPO3SRC}
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_GLOB=	*.sh *.php
PORTSCOUT=	limit:^${PORT_V_MAJOR}\.${PORT_V_MINOR}\.

PORT_V_MAJOR=	9
PORT_V_MINOR=	5
PORT_V_PATCH=	2

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

OPTIONS_DEFINE=	CURL GD GMP IMAGICK MBSTRING MYSQL POSTGRES SQLSRV SQLITE ZLIB
OPTIONS_DEFAULT=MYSQL
GD_DESC=	GDlib/freetype support
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
MBSTRING_DESC=	${MULTIBYTE_DESC}
MYSQL_DESC=	Use MySQL as DBMS
POSTGRES_DESC=	Use PostgreSQL as DBMS
SQLITE_DESC=	Use SQLiet as DBMS
SQLSRV_DESC=	Use MSSQL as DBMS

CURL_USE=	PHP=curl
GD_USE=		PHP=gd
GMP_USE=	PHP=gmp
MBSTRING_USE=	PHP=mbstring
MYSQL_USE=	PHP=mysqli
POSTGRES_USE=	PHP=postgresql
SQLSRV_USE=	PHP=sqlsrv
SQLITE_USE=	PHP=sqlite
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

post-install:
	@cd ${STAGEDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) -path "${TYPO3WWW}/${TYPO3DIR}/*" | \
		${SORT} >> ${TMPPLIST}; \
		${ECHO} "@owner ${WWWOWN}" >> ${TMPPLIST}; \
		${ECHO} "@dir ${TYPO3WWW}/${TYPO3DIR}" >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; \
		${ECHO} "@owner" >> ${TMPPLIST}; \
		${FIND} * \( -type f -or -type l \) -path "${TYPO3WWW}/${TYPO3SRC}/*" | \
		${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>

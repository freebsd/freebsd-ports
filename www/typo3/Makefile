# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	typo3
PORTVERSION=	7.6.14
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TYPO3%20Source%20and%20Dummy/TYPO3%20${PORTVERSION}

MAINTAINER=	freebsd-ports@charlieroot.de
COMMENT=	Typo3 content management system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe php:web shebangfix
SHEBANG_FILES=	typo3/sysext/core/Build/Scripts/xlfcheck.sh \
		typo3/sysext/core/Build/Scripts/splitFunctionalTests.sh
NO_BUILD=	yes
NO_ARCH=	yes
USE_PHP=	ctype fileinfo filter hash json mysqli openssl pcre session soap xml zip simplexml
WRKSRC=		${WRKDIR}/${TYPO3SRC}

TYPO3WWW=	www
TYPO3SRC=	${PORTNAME}_src-${PORTVERSION}
TYPO3DIR=	${PORTNAME}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}

DISTFILES+=	${TYPO3SRC}${EXTRACT_SUFX}

OPTIONS_DEFINE=	CURL GD GMP IMAGICK MBSTRING MYSQL ZLIB
OPTIONS_DEFAULT=	GD ZLIB
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
RUN_DEPENDS+=	convert:graphics/ImageMagick
.else
RUN_DEPENDS+=	convert:graphics/ImageMagick-nox11
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

	${TOUCH} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${TYPO3DIR}/FIRST_INSTALL
	@${ECHO_CMD} ${TYPO3WWW}/${TYPO3DIR}/FIRST_INSTALL >> ${TMPPLIST}

	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${TMPPLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${TMPPLIST}
	@${ECHO_CMD} "@mode 755" >> ${TMPPLIST}
	@${ECHO} "@dir ${TYPO3WWW}/${TYPO3DIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@mode" >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner" >> ${TMPPLIST}

.include <bsd.port.mk>

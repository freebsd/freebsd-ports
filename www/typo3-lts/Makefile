# Created by: Helmut Ritter <freebsd-ports@charlieroot.de>
# $FreeBSD$

PORTNAME=	typo3
PORTVERSION=	6.2.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TYPO3%20Source%20and%20Dummy/TYPO3%20${PORTVERSION}
PKGNAMESUFFIX=	-lts

MAINTAINER=	freebsd-ports@charlieroot.de
COMMENT=	The typo3 content management system

LICENSE=	GPLv2

PORTSCOUT=	limit:^6\.2\.

NO_BUILD=	yes
USE_PHP=	ctype fileinfo filter hash json mysqli openssl pcre session soap xml
WANT_PHP_WEB=	yes

TYPO3WWW=	www
TYPO3RELEASE=	LTS
TYPO3SRC=	${PORTNAME}_src-${PORTVERSION}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}

DISTFILES+=	${TYPO3SRC}${EXTRACT_SUFX}

OPTIONS_DEFINE=	APC CURL GD GMP IMAGICK MBSTRING MYSQL ZLIB
APC_DESC=	Alternative PHP Cache
GD_DESC=	GDlib/freetype support
IMAGICK_DESC=	${IMAGEMAGICK_DESC}
MBSTRING_DESC=	${MULTIBYTE_DESC}
MYSQL_DESC=	Install MySQL Server

APC_USE=	PHP=apc
CURL_USE=	PHP=curl
GD_USE=		PHP=gd
GMP_USE=	PHP=gmp
MBSTRING_USE=	PHP=mbstring
MYSQL_USE=	MYSQL=server
ZLIB_USE=	PHP=zlib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}
	${CP} -R ${WRKDIR}/${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/
	${LN} -fs ../${TYPO3SRC} ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/typo3_src
	${LN} -fs typo3_src/index.php ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/index.php
	${LN} -fs typo3_src/typo3 ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/typo3
	${CP} ${WRKDIR}/${TYPO3SRC}/_.htaccess ${STAGEDIR}${PREFIX}/${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/.htaccess

post-install:
	@cd ${STAGEDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) -path "${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/*" | \
		${SORT} >> ${TMPPLIST}
	@${ECHO_CMD} -e "@owner ${WWWOWN}\n@group ${WWWGRP}" >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) -path "${TYPO3WWW}/${TYPO3SRC}/typo3/ext/*" | \
		${SORT} >> ${TMPPLIST}
	@${ECHO_CMD} -e "@owner root\n@group wheel" >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) \
		-not \( -path "${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/*" -or \
		-path "${TYPO3WWW}/${TYPO3SRC}/typo3/ext/*" \) | \
		${SORT} >> ${TMPPLIST}
	@${ECHO_CMD} -e "@owner ${WWWOWN}\n@group ${WWWGRP}" >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} -d * -type d -regex "${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/*.*" | \
		${SORT} | ${SED} -ne 's#^#@dirrmtry #p' >> ${TMPPLIST}
	@${ECHO_CMD} -e "@owner ${WWWOWN}\n@group ${WWWGRP}" >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} -d * -type d -regex "${TYPO3WWW}/${TYPO3SRC}/typo3/ext/*.*" | \
		${SORT} | ${SED} -ne 's#^#@dirrmtry #p' >> ${TMPPLIST}
	@${ECHO_CMD} -e "@owner root\n@group wheel" >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d \
		-path "${TYPO3WWW}/*" \
		-not \( -regex "${TYPO3WWW}/${PORTNAME}-${TYPO3RELEASE}/*.*" -or \
		-regex "${TYPO3WWW}/${TYPO3SRC}/typo3/ext/*.*" \) | \
		${SORT} | ${SED} -ne 's#^#@dirrmtry #p' >> ${TMPPLIST}

.include <bsd.port.mk>

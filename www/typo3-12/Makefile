PORTNAME=	typo3
DISTVERSION=	${PORT_V_MAJOR}.${PORT_V_MINOR}.${PORT_V_PATCH}
#PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://cdn.typo3.com/typo3/${DISTVERSION}/
PKGNAMESUFFIX=	-${PORT_V_MAJOR}${PHP_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}_src-${DISTVERSION}

MAINTAINER=	freebsd-ports@charlieroot.de
COMMENT=	Typo3 content management system
WWW=		https://typo3.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe php:web,flavors shebangfix
# php openssl extension is required but it's statically linked in default php
USE_PHP=	ctype dom fileinfo filter gd intl mbstring pdo session \
		simplexml tokenizer xml zip zlib

SHEBANG_GLOB=	*.php *.sh
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^${PORT_V_MAJOR}\.${PORT_V_MINOR}\.
SUB_FILES=	pkg-message
SUB_LIST+=	PREFIX=${PREFIX} \
		TYPO3DIR=${TYPO3DIR} \
		TYPO3WWW=${TYPO3WWW}
WRKSRC=		${WRKDIR}/${PORTNAME}_src-${DISTVERSION}

PORT_V_MAJOR=	12
PORT_V_MINOR=	4
PORT_V_PATCH=	34

TYPO3DIR=	www/${PORTNAME}-${PORT_V_MAJOR}

OPTIONS_DEFINE=		CURL GMP IMAGICK MYSQL POSTGRES SQLITE X11
OPTIONS_DEFAULT=	MYSQL

IMAGICK_DESC=	${IMAGEMAGICK_DESC}
MYSQL_DESC=	Use MySQL as DBMS
POSTGRES_DESC=	Use PostgreSQL as DBMS
SQLITE_DESC=	Use SQLite as DBMS

CURL_USE=	PHP=curl
GMP_USE=	PHP=gmp
MYSQL_USE=	PHP=mysqli
POSTGRES_USE=	PHP=pgsql
SQLITE_USE=	PHP=sqlite3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGICK}
.if ${PORT_OPTIONS:MX11}
USES+=		magick:7,run
.else
USES+=		magick:7,run,nox11
.endif
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${TYPO3DIR}

post-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${TMPPLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${TMPPLIST}
	@${ECHO_CMD} "@mode 755" >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${TYPO3DIR}?g" >>${TMPPLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${TYPO3DIR}?g" >> ${TMPPLIST}
	@${ECHO_CMD} "@mode" >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner" >> ${TMPPLIST}

.include <bsd.port.mk>

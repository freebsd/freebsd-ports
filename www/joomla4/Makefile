PORTNAME=	joomla
DISTVERSION=	4-3-2
CATEGORIES=	www
MASTER_SITES=	https://downloads.joomla.org/cms/joomla4/${DISTVERSION}/
PKGNAMESUFFIX=	4
DISTNAME=	Joomla_${DISTVERSION}-Stable-Full_Package

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Dynamic web content management system (CMS)
WWW=		https://www.joomla.org/

LICENSE=	GPLv2

USES=		cpe php:web shebangfix zip
CPE_VENDOR=	${PORTNAME}
CPE_PRODUCT=	${PORTNAME}\!

CONFLICTS_INSTALL=	joomla3

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	MYSQL PGSQL
OPTIONS_DEFAULT=MYSQL
OPTIONS_SUB=	yes

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

SUB_FILES=	pkg-message

USE_PHP=	gd mbstring session simplexml xml zip zlib

MYSQL_USE=	PHP=mysqli
PGSQL_USE=	PHP=pgsql

PLIST=		${WRKDIR}/plist
JOOMLADIR=	www/joomla4

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}

	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${JOOMLADIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${JOOMLADIR}?g" >> ${PLIST}

	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${JOOMLADIR}

.include <bsd.port.mk>

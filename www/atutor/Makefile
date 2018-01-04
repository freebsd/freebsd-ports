# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	atutor
PORTVERSION=	2.2.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/ATutor%202/
DISTNAME=	ATutor-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open Source Web-based Learning Content Management System (LCMS)

LICENSE=	GPLv2

IGNORE_WITH_PHP=	70 71 72

USES=		cpe php

USE_PHP=	session mbstring zlib mysql
WRKSRC=		${WRKDIR}/ATutor

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message

ATUTDIR=	www/atutor
ATUTDATDIR=	${WWWDIR}/content
ATUTCONFIG=	include/config.inc.php

pre-install:
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' > ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ATUTDIR}?g" >> ${PLIST}
	@${ECHO} @dir ${ATUTDIR}/content >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${ATUTDIR}?g" >> ${PLIST}
	@${ECHO_CMD} -e '@owner\n@group' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${FIND} ${STAGEDIR}${WWWDIR} -type d -exec ${CHMOD} a+x {} \;
	${INSTALL_DATA} -d ${STAGEDIR}${ATUTDATDIR}
	@${CHMOD} 777 ${STAGEDIR}${ATUTDATDIR}
	@${CHMOD} 666 ${STAGEDIR}${WWWDIR}/${ATUTCONFIG}

.include <bsd.port.mk>

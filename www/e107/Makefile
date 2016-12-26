# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	e107
PORTVERSION=	2.1.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20v${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_full

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Content management system written in PHP

USES=		cpe

USE_PHP=	dom exif hash pdo_mysql session xml
WRKSRC=		${WRKDIR}/e107

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	E107DIR=${E107DIR}
E107DIR=	www/e107

USES=		dos2unix shebangfix
SHEBANG_FILES=	cron.php e107_handlers/bounce_handler.php

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -yxf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKSRC}

pre-install:
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' > ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s#${WRKSRC}#${E107DIR}#g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d | ${SED} "s#${WRKSRC}#@dir ${E107DIR}#g" >> ${PLIST}
	@${ECHO_CMD} -e '@owner\n@group' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	e107
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20v${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_full

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Content management system written in PHP

USES=		cpe

USE_PHP=	mysql xml
WRKSRC=		${WRKDIR}/e107

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	E107DIR=${E107DIR}
E107DIR=	www/e107

post-extract:
	@cd ${WRKDIR} && ${MKDIR} ${WRKSRC}
	@cd ${WRKDIR} && ${MV} *.php ${WRKSRC}
	@cd ${WRKDIR} && ${MV} e107_* ${WRKSRC}
	@cd ${WRKDIR} && ${MV} e107.htaccess ${WRKSRC}
	@cd ${WRKDIR} && ${MV} favicon.ico ${WRKSRC}
	@cd ${WRKDIR} && ${MV} e107.robots.txt ${WRKSRC}

pre-install:
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' > ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s#${WRKSRC}#${E107DIR}#g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d | ${SED} "s#${WRKSRC}#@dir ${E107DIR}#g" >> ${PLIST}
	@${ECHO_CMD} -e '@owner\n@group' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

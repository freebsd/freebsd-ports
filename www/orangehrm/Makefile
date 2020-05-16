# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	orangehrm
PORTVERSION=	4.4
CATEGORIES=	www misc
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open Source Human Resource Management

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license/LICENSE.TXT

USES=		cpe php zip
USE_PHP=	iconv json pdo_mysql ctype xml session simplexml
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
HRMDIR=		www/orangehrm

#WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}-${PORTVERSION}

pre-install:
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' > ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type l | ${SED} "s#${WRKSRC}#${HRMDIR}#g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s#${WRKSRC}#${HRMDIR}#g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s#${WRKSRC}#@dir ${HRMDIR}#g" >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} -e '@owner root\n@group wheel' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${HRMDIR}

.include <bsd.port.mk>

# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	flat-frog
PORTVERSION=	2.2.13
CATEGORIES=	www
MASTER_SITES=	SF/flatfrog/flatfrog/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	A templating engine working in php

NO_BUILD=	yes
USE_PHP=	yes
USES=		zip

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR} ${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/src/class.* ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/plugins/* ${DATADIR}/plugins
	${MKDIR} ${EXAMPLESDIR} ${EXAMPLESDIR}/templates
	${INSTALL_DATA} ${WRKSRC}/demo/test.* ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/templates/* ${EXAMPLESDIR}/templates
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>

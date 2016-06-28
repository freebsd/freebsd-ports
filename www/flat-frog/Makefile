# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	flat-frog
PORTVERSION=	2.2.13
CATEGORIES=	www
MASTER_SITES=	SF/flatfrog/flatfrog/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Templating engine working in php

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes
USES=		php zip

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/src/class.* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/plugins/* ${STAGEDIR}${DATADIR}/plugins
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${EXAMPLESDIR}/templates
	${INSTALL_DATA} ${WRKSRC}/demo/test.* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/templates/* ${STAGEDIR}${EXAMPLESDIR}/templates
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

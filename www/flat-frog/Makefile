PORTNAME=	flat-frog
PORTVERSION=	2.2.13
CATEGORIES=	www
MASTER_SITES=	SF/flatfrog/flatfrog/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Templating engine working in php

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php zip
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${DATADIR}/plugins
	${INSTALL_DATA} ${WRKSRC}/src/class.* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/plugins/* ${STAGEDIR}${DATADIR}/plugins

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${EXAMPLESDIR}/templates
	${INSTALL_DATA} ${WRKSRC}/demo/test.* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/templates/* ${STAGEDIR}${EXAMPLESDIR}/templates

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

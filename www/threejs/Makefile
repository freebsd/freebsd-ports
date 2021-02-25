# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	three.js
PORTVERSION=	126
DISTVERSIONPREFIX=	r
CATEGORIES=	www

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	JavaScript 3D library

LICENSE=	MIT

NO_BUILD=	yes
NO_ARCH=	yes
WWWDIR=		${PREFIX}/www/${PORTNAME:C/\.//}

USE_GITHUB=	yes
GH_ACCOUNT=	mrdoob

OPTIONS_DEFINE=	DOCS EXAMPLES
PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test:
	@${ECHO_CMD} "Tests skipped: they require npm and too many node packages."

.include <bsd.port.mk>

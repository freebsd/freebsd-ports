# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gaeutilities
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	www devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility classes to make working with Google App Engine easier

RUN_DEPENDS=	google-appengine>=1.2.4_1:www/google-appengine

USES=		python:2.7 # same as www/google-appengine
USE_GITHUB=	yes
GH_ACCOUNT=	joerussbowman
GH_TAGNAME=	ea3f7e1

OPTIONS_DEFINE=	DOCS

do-build:
	${PYTHON_CMD} -m compileall -f ${WRKSRC}/appengine_utilities
	${PYTHON_CMD} -O -m compileall -f ${WRKSRC}/appengine_utilities

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} appengine_utilities ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR} && cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

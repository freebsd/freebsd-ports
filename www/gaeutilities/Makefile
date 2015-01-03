# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gaeutilities
PORTVERSION=	1.4
PORTREVISION=	0
CATEGORIES=	www devel
MASTER_SITES=	http://cloud.github.com/downloads/joerussbowman/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility classes to make working with Google App Engine easier

RUN_DEPENDS=	google-appengine>=1.2.4_1:${PORTSDIR}/www/google-appengine

USES=		python:2 # same as www/google-appengine

WRKSRC=	${WRKDIR}/joerussbowman-gaeutilities-ea3f7e1

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS

do-build:
	${PYTHON_CMD} -m compileall -f ${WRKSRC}/appengine_utilities
	${PYTHON_CMD} -O -m compileall -f ${WRKSRC}/appengine_utilities

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} appengine_utilities ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR} && cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

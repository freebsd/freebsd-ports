# New ports collection makefile for: trac-gantt
# Date created:                      July 12 2006
# Whom:                              Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	TracGantt
PORTVERSION=	0.3.2a
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://willbarton.com/files/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	trac-

MAINTAINER=	dryice@dryice.name
COMMENT=	A plugin to creates Gantt charts for trac

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	2.3+
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}

.if !defined(NOPORTDOCS)
PORTDOCS=	PKG-INFO README
.endif

do-build:
	cd ${WRKSRC}; \
	${PYTHON_CMD} setup.py bdist_egg

do-install:
.for i in *
	${INSTALL_DATA} ${WRKSRC}/dist/${i} ${PYTHON_SITELIBDIR}/
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

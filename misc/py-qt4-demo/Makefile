# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	demo
PORTVERSION=	${PYQT4_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	misc devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, Qt demo and examples

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}

USES=		python

EXAMPLESDIR=	${PREFIX}/share/examples/py-qt4

.include "${.CURDIR}/../../devel/py-qt4/bsd.pyqt.mk"

.for component in ${PYQT4_COMPONENTS:Ndemo}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}qt4-${component}>=0:${PORTSDIR}/${${component}_PORT}
.endfor

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/examples

do-install:
	${RM} -f ${WRKSRC}/examples/designer/plugins/plugins.py.orig
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

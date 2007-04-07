# New ports collection makefile for:	py-funkload
# Date created:		Mar. 03, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	funkload
PORTVERSION=	1.6.2
CATEGORIES=	www python
MASTER_SITES=	http://funkload.nuxeo.org/ \
		http://cheeseshop.python.org/packages/source/f/funkload/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	FunkLoad is a functional and load web tester

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_SITELIBDIR}/gdchart.so:${PORTSDIR}/graphics/py-gdchart \
		${PYTHON_SITELIBDIR}/webunit/__init__.py:${PORTSDIR}/www/py-webunit \
		${PYXML} \
		tcpwatch.py:${PORTSDIR}/net/tcpwatch

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYFUNKLOAD_EGG}

PYFUNKLOAD_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYFUNKLOAD_EGG=${PYFUNKLOAD_EGG} \
		PYFUNKLOAD_EGG_VER="${PORTNAME}==${PORTVERSION}"

.if !defined(NOPORTDOCS)
DOCSDIR=	${TARGETDIR}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${TARGETDIR}/share/examples/py-${PORTNAME}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/funkload/demo ${EXAMPLESDIR}

.include <bsd.port.mk>

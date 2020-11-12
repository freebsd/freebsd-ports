# $FreeBSD$

PORTNAME=	pdal
DISTVERSION=	2.3.5
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	PDAL Python bindings

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${LOCALBASE}/bin/cmake:devel/cmake \
		${LOCALBASE}/bin/ninja:devel/ninja
LIB_DEPENDS=	libpdal_base.so:math/pdal
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYNUMPY}

USES=		compiler:c++11-lang python:3.6+
USE_PYTHON=	autoplist cython distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpdal_plugin_filter_python.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/libpdalpython.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpdal_plugin_reader_numpy.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>

PORTNAME=	tfel
PORTVERSION=	5.1.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://github.com/thelfer/tfel/archive/refs/tags/
PKGNAMESUFFIX=	-mfront
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code generation tool dedicated to material knowledge
WWW=		https://github.com/thelfer/tfel

LICENSE=	GPLv3

BUILD_DEPENDS=	gnuplot:math/gnuplot	\
		pybind11>0:devel/pybind11
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		cmake compiler:c++0x fortran

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

CONFLICTS_INSTALL=	tfel-mfront-edf-3.*

OPTIONS_DEFINE=		DOCS PYTHON
OPTIONS_DEFAULT=	DOCS PYTHON

OPTIONS_SUB=		yes

PYTHON_USES=		localbase python
PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
PYTHON_LIB_DEPENDS=	${PY_BOOST}	\
			libboost_thread.so:devel/boost-libs
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
PYTHON_CMAKE_BOOL=	enable-python enable-python-bindings

CMAKE_ON=	enable-aster enable-calculix enable-fortran
CMAKE_ARGS+=	-DCOMPILER_CXXFLAGS="${CXXFLAGS}" -DCOMPILER_FLAGS="${CFLAGS}"
PLIST_SUB=	VER=${PORTVERSION}
USE_LDCONFIG=	yes

.ifdef PACKAGE_BUILDING
CMAKE_ON+=	enable-portable-build
.endif

TEST_TARGET=	check

post-install-PYTHON-on:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})

.include <bsd.port.mk>

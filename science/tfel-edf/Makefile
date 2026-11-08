PORTNAME=	tfel
DISTVERSION=	5.0.1
CATEGORIES=	science
PKGNAMESUFFIX=	-mfront-edf

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code generation tool dedicated to material knowledge
WWW=		https://tfel.sourceforge.net/

LICENSE=	GPLv3

BUILD_DEPENDS=	gnuplot:math/gnuplot	\
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	${PY_BOOST}		\
		libboost_thread.so:devel/boost-libs
RUN_DEPENDS=	gnuplot:math/gnuplot	\
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		cmake compiler:c++0x fortran localbase python

CONFLICTS=	tfel-mfront-5.*

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

CXXFLAGS+=	-I${PYTHON_SITELIBDIR}/numpy/_core/include
CMAKE_ON=	enable-aster enable-calculix enable-fortran	\
		enable-python enable-python-bindings
CMAKE_ARGS+=	-DCOMPILER_CXXFLAGS="${CXXFLAGS}" -DCOMPILER_FLAGS="${CFLAGS}"
FCFLAGS+=	-fallow-argument-mismatch

TAGNAME=	f44363139f5f9eb774166fa1c6b0ccb66641bbe3
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME:tu}-${PORTVERSION}-${TAGNAME}
USE_LDCONFIG=	yes

.ifdef PACKAGE_BUILDING
CMAKE_ON+=	enable-portable-build
.endif

TEST_TARGET=	check

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.pre.mk>

_PYVER=		${PYTHON_VER:C|\.||}
_PYBOOSTLIB=	${LOCALBASE}/lib/libboost_python${_PYVER}.so
.if exists(${_PYBOOSTLIB})
PY_BOOST_VER!=	make -V PORTVERSION -C ${.CURDIR}/../../devel/boost-python-libs
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|1.36.0|${PY_BOOST_VER}|'	\
		${WRKSRC}/cmake/modules/boost-python.cmake

post-install:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})

.include <bsd.port.post.mk>

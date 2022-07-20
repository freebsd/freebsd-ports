PORTNAME=	tfel
DISTVERSION=	3.2.1-1
PORTREVISION=	2
CATEGORIES=	science
PKGNAMESUFFIX=	-mfront-edf

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code generation tool dedicated to material knowledge

LICENSE=	GPLv3

BUILD_DEPENDS=	gnuplot:math/gnuplot	\
		${PYNUMPY}
LIB_DEPENDS=	${PY_BOOST}		\
		libboost_thread.so:devel/boost-libs
RUN_DEPENDS=	gnuplot:math/gnuplot	\
		${PYNUMPY}

USES=		cmake compiler:c++0x fortran localbase python

CONFLICTS=	tfel-mfront-3.*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
CMAKE_ON=	enable-aster enable-calculix enable-fortran	\
		enable-python enable-python-bindings
CMAKE_ARGS+=	-DCOMPILER_CXXFLAGS="${CXXFLAGS}" -DCOMPILER_FLAGS="${CFLAGS}"
USE_LDCONFIG=	yes

.ifdef PACKAGE_BUILDING
CMAKE_ON+=	enable-portable-build
.endif

TEST_TARGET=	check

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../french/aster/bsd.aster.mk"

.if ${FORTRAN_DEFAULT} == gfortran && ${GCC_DEFAULT} >= 10
FCFLAGS+=	-fallow-argument-mismatch
.endif

post-install:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S,${PREFIX}/,,})

.include <bsd.port.post.mk>

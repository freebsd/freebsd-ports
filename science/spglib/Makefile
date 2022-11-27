PORTNAME=	spglib
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for finding and handling crystal symmetries
WWW=		https://spglib.github.io/spglib/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

.if !exists(/usr/include/omp.h)
CMAKE_OFF+=	USE_OMP
.else
FORTRAN_LDFLAGS=	-lomp # workaround for: undefined reference to `__kmpc_fork_call'
.endif

OPTIONS_DEFINE=		FORTRAN
OPTIONS_DEFAULT=	FORTRAN
OPTIONS_SUB=		yes

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	WITH_Fortran

do-test: # from test/README.md
	cd ${WRKSRC}/test && \
		${CMAKE_BIN} -S . -B build -DUSE_SANITIZER="Address" -DCMAKE_BUILD_TYPE="Debug" && \
		${CMAKE_BIN} --build build -j ${_MAKE_JOBS} && \
		cd build && \
		ctest

.include <bsd.port.mk>

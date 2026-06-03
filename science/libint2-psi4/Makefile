PORTNAME=	libint2-psi4
DISTVERSION=	0.1-${VERSION}
CATEGORIES=	science
MASTER_SITES=	https://github.com/loriab/libint/releases/download/v${DISTVERSION:C/-.*//}/
DISTFILES=	libint-${VERSION}-5-4-3-6-5-4_mm10f12ob2_0.tgz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory (psi4)
WWW=		https://github.com/evaleev/libint

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	compilation fails: runaway processes and out-of-memory conditions
BROKEN_i386=	compilation fails: clang runs out of memory
BROKEN_armv7=	compilation fails: clang runs out of memory

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgmpxx.so:math/gmp

USES=		cmake:testing eigen:3 python:build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libint-${VERSION}

CMAKE_ARGS=	-DLIBINT2_SHGAUSS_ORDERING=gaussian \
		-DPython_EXECUTABLE=${PYTHON_CMD}
CMAKE_ON=	BUILD_SHARED_LIBS \
		REQUIRE_CXX_API
CMAKE_OFF=	ENABLE_FORTRAN \
		REQUIRE_CXX_API_COMPILED

VERSION=	2.8.1

PLIST_SUB+=	VER=${VERSION}

CONFLICTS=	libint2

.include <bsd.port.mk>

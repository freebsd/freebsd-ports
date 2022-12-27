PORTNAME=	obake
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0-24
DISTVERSIONSUFFIX=	-gb8cc71c
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for the symbolic manipulation of sparse polynomials & co
WWW=		https://bluescarni.github.io/obake/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		https://github.com/bluescarni/obake/issues/148

LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libboost_serialization.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libgmp.so:math/gmp \
		libmp++.so:math/mppp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libtbb.so:devel/onetbb

USES=		cmake:testing compiler:c++17-lang # need compiler:c++20-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni

CXXFLAGS+=	-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED

CMAKE_TESTING_ON=	OBAKE_BUILD_TESTS

.include <bsd.port.mk>

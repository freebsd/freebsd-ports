PORTNAME=	obake
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for the symbolic manipulation of sparse polynomials & co

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

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

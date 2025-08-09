PORTNAME=	obake
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0-24
DISTVERSIONSUFFIX=	-gb8cc71c
PORTREVISION=	23
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	1a53966f5ce8ca5542d3612c780ea4b69be34de2.patch:-p1 \
		dadf4ce2aba713522d1949a16ffbf0fa5d6e6298.patch:-p1 \
		9310de2cb5cc4c85b54e7e90aa6cd88664380346.patch:-p1 \
		57da8d5f2d0c50e857979ba74434893b0b392382.patch:-p1 \
		494df04bd7608bb666efde776241370cb84c96bb.patch:-p1 # adding fmt9 compatibility, see https://github.com/bluescarni/obake/pull/145/commits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for the symbolic manipulation of sparse polynomials & co
WWW=		https://bluescarni.github.io/obake/

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

USES=		cmake:testing compiler:c++20-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni

CXXFLAGS+=	-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED

CMAKE_TESTING_ON=	OBAKE_BUILD_TESTS

post-install:
	# remove patch artefacts
	@${FIND} ${STAGEDIR}${PREFIX}/include/obake -name "*.orig" -delete

.include <bsd.port.mk>

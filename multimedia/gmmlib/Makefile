# $FreeBSD$

PORTNAME=	gmmlib
DISTVERSIONPREFIX=	intel-${PORTNAME}-
DISTVERSION=	20.1.1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	f17dd87c7f57.patch:-p1 # https://github.com/intel/gmmlib/pull/67
PATCHFILES+=	7171f6d818fc.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	6fc5091d3329.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	a3272580cea0.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	8b172b9ff4ea.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	53c731fbe8be.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	0a8db9639503.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	a512c6b7b1a2.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	6af9ac5b3f49.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	7b4f7fe0fa59.patch:-p1 # https://github.com/intel/gmmlib/pull/68

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Intel Graphics Memory Management Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
CMAKE_ARGS=	-DBUILD_TYPE:STRING="${CMAKE_BUILD_TYPE}" \
		-DGMMLIB_MARCH:STRING="${CPUTYPE}"

OPTIONS_DEFINE=	TEST

# XXX Unbundle googletest
TEST_CMAKE_BOOL=	RUN_TEST_SUITE
TEST_TEST_TARGET=	Run_ULT

post-install:
# Clean up after PATTERN-based install
	@${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

.include <bsd.port.mk>

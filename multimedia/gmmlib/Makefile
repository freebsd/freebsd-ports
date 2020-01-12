# $FreeBSD$

PORTNAME=	gmmlib
DISTVERSIONPREFIX=	intel-${PORTNAME}-
DISTVERSION=	19.4.1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	f17dd87c7f57.patch:-p1 # https://github.com/intel/gmmlib/pull/67
PATCHFILES+=	c1e398124a55.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	92704b3ed362.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	ee3afe457015.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	3eaaa3ac097e.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	492c1eea16ab.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	62cbd18f9ab6.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	4261462b0586.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	6cb8a44dcc55.patch:-p1 # https://github.com/intel/gmmlib/pull/68

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

PORTNAME=	gmmlib
DISTVERSIONPREFIX=	intel-${PORTNAME}-
DISTVERSION=	22.0.3
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	f17dd87c7f57.patch:-p1 # https://github.com/intel/gmmlib/pull/67
PATCHFILES+=	4356a33c787c.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	a75809957583.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	978f7d56f88a.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	c090ac40e189.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	072810163a05.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	ab150305017a.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	0d45ab8163e7.patch:-p1 # https://github.com/intel/gmmlib/pull/68
PATCHFILES+=	4ae2fd0de966.patch:-p1 # https://github.com/intel/gmmlib/pull/68

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Intel Graphics Memory Management Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	only Intel GPUs on x86 are supported

USES=		cmake:testing compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
CMAKE_OFF+=	${CMAKE_TESTING_ON}
CMAKE_TESTING_ON=	RUN_TEST_SUITE # XXX Unbundle googletest
CMAKE_TESTING_TARGET=	Run_ULT
CMAKE_ARGS=	-DBUILD_TYPE:STRING="${CMAKE_BUILD_TYPE}" \
		-DGMMLIB_MARCH:STRING="${CPUTYPE}"

post-install:
# Clean up after PATTERN-based install
	@${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

.include <bsd.port.mk>

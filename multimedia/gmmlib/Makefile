# $FreeBSD$

PORTNAME=	gmmlib
DISTVERSIONPREFIX=	intel-${PORTNAME}-
DISTVERSION=	18.3.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Intel Graphics Memory Management Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Only Intel GPUs on x86 are supported

USES=		cmake:outsource compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
CMAKE_ARGS=	-DBUILD_TYPE:STRING="${CMAKE_BUILD_TYPE}" \
		-DGMMLIB_MARCH:STRING="${CPUTYPE}"

OPTIONS_DEFINE=	TEST

# XXX Unbundle googletest
TEST_CMAKE_BOOL=	RUN_TEST_SUITE
TEST_TEST_TARGET=	Run_ULT

post-patch:
# Silence -Wmacro-redefined
	@${REINPLACE_CMD} -e '/__fastcall/d' \
		${WRKSRC}/Source/inc/portable_compiler.h

post-install:
# Clean up after PATTERN-based install
	@${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

.include <bsd.port.mk>

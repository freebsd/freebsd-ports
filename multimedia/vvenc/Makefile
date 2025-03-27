PORTNAME=	vvenc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Versatile Video Coding (VVC) encoder
WWW=		https://www.hhi.fraunhofer.de/en/departments/vca/technologies-and-solutions/h266-vvc.html \
		https://github.com/fraunhoferhhi/vvenc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	compilation fails, see https://github.com/fraunhoferhhi/vvenc/issues/523

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fraunhoferhhi

CMAKE_OFF=	VVENC_ENABLE_WERROR
CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.options.mk>

.if ${ARCH:Marmv?} || ${ARCH} == i386 || ${ARCH} == powerpc
CMAKE_OFF+=	VVENC_ENABLE_X86_SIMD
.endif

.if ${ARCH} == riscv64
CMAKE_OFF+=	VVENC_ENABLE_LINK_TIME_OPT
.endif

# tests as of 1.13.1: 100% tests passed, 0 tests failed out of 38

.include <bsd.port.mk>

PORTNAME=	vvdec
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	multimedia python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Versatile Video Coding (VVC) decoder
WWW=		https://github.com/fraunhoferhhi/vvdec

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:noninja,testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fraunhoferhhi

CMAKE_ON=	BUILD_SHARED_LIBS \
		VVDEC_INSTALL_VVDECAPP
CMAKE_OFF=	FREEBSD_VVDEC_ENABLE_X86_SIMD \
		VVDEC_ENABLE_WARNINGS_AS_WERROR
CMAKE_TESTING_ON=	BUILD_TESTING VVDEC_ENABLE_BITSTREAM_DOWNLOAD
CMAKE_TESTING_TARGET=	test

.include <bsd.port.options.mk>

.if ${ARCH} == riscv64
CMAKE_ARGS+=	-DVVDEC_ENABLE_LINK_TIME_OPT:BOOL=OFF
.endif

# tests as of 3.1.0: 100% tests passed, 0 tests failed out of 239

.include <bsd.port.mk>

PORTNAME=	vvdec
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
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
CMAKE_TESTING_TARGET=	test enable-bitstream-download=1 # tests fail to download bitstreams, see https://github.com/fraunhoferhhi/vvdec/issues/125

.include <bsd.port.options.mk>

.if ${ARCH} == riscv64
CMAKE_ARGS+=	-DVVDEC_ENABLE_LINK_TIME_OPT:BOOL=OFF
.endif

.include <bsd.port.mk>

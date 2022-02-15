PORTNAME=	vvdec
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	multimedia python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Versatile Video Coding (VVC) decoder

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		amd64 powerpc64 powerpc64le

USES=		cmake compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fraunhoferhhi

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	FREEBSD_VVDEC_ENABLE_X86_SIMD

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
CMAKE_ARGS+=	-DVVDEC_ENABLE_LINK_TIME_OPT:BOOL=OFF
.endif

.include <bsd.port.mk>

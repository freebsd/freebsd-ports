# $FreeBSD$

PORTNAME=	vvdec
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	multimedia python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Versatile Video Coding (VVC) decoder

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Uses explicit SSE instructions without any way to turn them off, can be removed once this bug is fixed: https://github.com/fraunhoferhhi/vvdec/issues/9; also is for 64-bit systems

USES=		cmake compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fraunhoferhhi

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	FREEBSD_VVDEC_ENABLE_X86_SIMD

.include <bsd.port.mk>

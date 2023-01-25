PORTNAME=	vvenc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Versatile Video Coding (VVC) encoder
WWW=		https://www.hhi.fraunhofer.de/en/departments/vca/technologies-and-solutions/h266-vvc.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	fraunhoferhhi
CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.options.mk>

.if ${ARCH} == i386
CMAKE_OFF+=	VVENC_ENABLE_X86_SIMD
.endif

.if ${ARCH} == powerpc64 || ${ARCH} == riscv64
CMAKE_OFF+=	VVENC_ENABLE_LINK_TIME_OPT
.endif

.include <bsd.port.mk>

PORTNAME=	vvenc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Versatile Video Coding (VVC) encoder
WWW=		https://www.hhi.fraunhofer.de/en/departments/vca/technologies-and-solutions/h266-vvc.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	compilation fails: error: use of undeclared identifier 'read_x86_extension_flags'

USES=		cmake:testing # some tests fail, see https://github.com/fraunhoferhhi/vvenc/issues/262
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fraunhoferhhi

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.options.mk>

.if ${ARCH:Marmv?} || ${ARCH} == i386 || ${ARCH} == powerpc
CMAKE_OFF+=	VVENC_ENABLE_X86_SIMD
.endif

.if ${ARCH} == powerpc64 || ${ARCH} == riscv64
CMAKE_OFF+=	VVENC_ENABLE_LINK_TIME_OPT
.endif

.include <bsd.port.mk>

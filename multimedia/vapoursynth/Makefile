PORTNAME=	vapoursynth
DISTVERSION=	R73
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Video processing framework with simplicity in mind
WWW=		https://www.vapoursynth.com/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libzimg.so:graphics/sekrit-twc-zimg

USES=		compiler:c++17-lang meson pkgconfig python
USE_PYTHON=	cython
USE_LDCONFIG=	yes

USE_GITHUB=	yes

WITH_LTO=	yes
LDFLAGS+=	-lpthread

MESON_ARGS=	-Dpython3_bin=${PYTHON_CMD}

.include <bsd.port.options.mk>

.if !defined(CPUTYPE) && ${ARCH} == amd64
COMMENT+= (compatibility mode)
MESON_ARGS+=    -Denable_x86_asm=false
.endif

.if defined(CPUTYPE) && ${ARCH} == amd64
BUILD_FAIL_MESSAGE+= If CPUTYPE is defined but falls under requirements (support for AVX2 instruction set) the build will fail. \
		Building without utilizing the instruction set is possible however with performance penalties. \
		To disable don't define CPUTYPE during build. \

.endif

.include <bsd.port.mk>

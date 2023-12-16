PORTNAME=	quick3dphysics
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	science
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level API for physics simulation

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl pkgconfig qt-dist:6
USE_GL=		opengl
USE_LDCONFIG=	yes
USE_QT=		base declarative quick3d shadertools

OPTIONS_DEFINE_aarch64=	SIMD
OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_armv7=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_aarch64=SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_armv7=	SIMD

.include <bsd.port.options.mk>

# Either SSE2 or NEON instruction sets are required on i386/amd64 or armv7/
# aarch64, respectively, to compile vector intrinsics. However i386 does not
# guarantee SSE2, nor does armv7 NEON, but from what I understand, llvm implies
# NEON for armv7. If the SIMD option is selected on i386 and SSE2 is not
# available, we ignore. SIMD support on other platforms is not implemented.

.if ${PORT_OPTIONS:MSIMD}
.  if ${ARCH} == "i386" && empty(MACHINE_CPU:Msse2)
IGNORE=		sse2 instructions required
.  endif
.else
CFLAGS+=	-DPX_SIMD_DISABLED
.endif

.include <bsd.port.mk>

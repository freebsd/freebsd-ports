# $FreeBSD$

PORTNAME=	libvdpau-va-gl
PORTVERSION=	0.4.2
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	58a98e8a735f.patch:-p1

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VDPAU driver with OpenGL/VAAPI backend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=		fails to configure: CMake Error: Check for working CXX compiler: /nxb-bin/usr/bin/c++ -- broken

LIB_DEPENDS=	libva-x11.so:multimedia/libva

USE_GITHUB=	yes
GH_ACCOUNT=	i-rinat

USES=		cmake compiler:c++11-lang gl pkgconfig xorg
USE_XORG=	x11
USE_GL=		gl
LDFLAGS+=	-Wl,--as-needed # Xext, ICE, SM
TEST_TARGET=	check

PLIST_FILES=	lib/vdpau/libvdpau_va_gl.so lib/vdpau/libvdpau_va_gl.so.1
# bug 217825: Convenience symlinks. On AMD prefer VDPAU from Mesa.
PLIST_FILES+=	lib/vdpau/libvdpau_i915.so.1 lib/vdpau/libvdpau_i965.so.1

post-install:
.for f in ${PLIST_FILES:N*va_gl*:M*.so.1}
	${LN} -sf libvdpau_va_gl.so.1 ${STAGEDIR}${PREFIX}/$f
.endfor

.include <bsd.port.mk>

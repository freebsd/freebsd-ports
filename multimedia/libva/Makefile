# $FreeBSD$

PORTNAME=	libva
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	acf217e61475.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT?=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libdrm.so:graphics/libdrm

USES=		meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
LDFLAGS+=	-lpthread # for pthread_getthreadid_np

OPTIONS_DEFINE=	GLX WAYLAND X11
OPTIONS_DEFAULT=GLX WAYLAND X11
OPTIONS_EXCLUDE?=GLX # enslaved until subpackaging
OPTIONS_SUB=	yes

GLX_LIB_DEPENDS=	libva-x11.so:multimedia/libva
GLX_USES=		gl
GLX_USE=		GL=gl
GLX_MESON_YES=		with_glx
GLX_IMPLIES=		X11

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MESON_YES=	with_wayland

X11_USE=		XORG=x11,xorgproto,xext,xfixes
X11_MESON_YES=		with_x11

post-patch:	.SILENT
# V4L2 is unused since http://github.com/intel/libva/commit/70074679333c
	${REINPLACE_CMD} '/videodev2\.h/d' ${WRKSRC}/va/va_backend.h

.include <bsd.port.mk>

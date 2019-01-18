# $FreeBSD$

PORTNAME=	libva
PORTVERSION=	2.3.0
PORTREVISION=	5
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	cf11abe5e1b9.patch:-p1 # for media-driver 18.4+
PATCHFILES+=	62bad1239d8e.patch:-p1 # for mesa-libs 18.3+

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		meson pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	intel
LDFLAGS+=	-lpthread # for pthread_getthreadid_np

OPTIONS_DEFINE=	WAYLAND X11
OPTIONS_DEFAULT=WAYLAND X11
OPTIONS_SUB=	yes

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MESON_YES=	with_wayland

X11_USES=		gl
X11_USE=		GL=gl XORG=x11,xorgproto,xext,xfixes
X11_MESON_YES=		with_x11 with_glx

post-patch:	.SILENT
# V4L2 is unused since http://github.com/intel/libva/commit/70074679333c
	${REINPLACE_CMD} '/videodev2\.h/d' ${WRKSRC}/va/va_backend.h

.include <bsd.port.mk>

PORTNAME=	libva
DISTVERSION=	2.20.0
PORTREVISION=	1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	9ed99b6b0b3b.patch:-p1 # https://github.com/intel/libva/pull/667
PATCHFILES+=	6b0efda45140.patch:-p1 # https://github.com/intel/libva/pull/758

MAINTAINER=	jbeich@FreeBSD.org
COMMENT?=	VAAPI wrapper and dummy driver
WWW=		https://github.com/intel/libva

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libdrm.so:graphics/libdrm

USES=		meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel

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

X11_USES=		xorg
X11_USE=		XORG=x11,xcb,xext,xfixes,xorgproto
X11_MESON_YES=		with_x11

.include <bsd.port.mk>

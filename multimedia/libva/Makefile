# $FreeBSD$

PORTNAME=	libva
PORTVERSION=	2.6.1
PORTREVISION=	1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	04acc7860feb.patch:-p1
PATCHFILES+=	48f446b32a4f.patch:-p1
PATCHFILES+=	c2a431cc3cab.patch:-p1 # https://github.com/intel/libva/pull/292
PATCHFILES+=	5cfcd31635b1.patch:-p1 # https://github.com/intel/libva/pull/292
PATCHFILES+=	f601fc614d8d.patch:-p1 # https://github.com/intel/libva/pull/363
PATCHFILES+=	853c679c628a.patch:-p1 # https://github.com/intel/libva/pull/363
PATCHFILES+=	810d1974a54c.patch:-p1 # https://github.com/intel/libva/pull/363
PATCHFILES+=	12525d4cd7c3.patch:-p1 # https://github.com/intel/libva/pull/363
PATCHFILES+=	36f53f358a9c.patch:-p1 # https://github.com/intel/libva/pull/363

MAINTAINER=	jbeich@FreeBSD.org
COMMENT?=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libdrm.so:graphics/libdrm

USES=		meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	intel
# -lpthread is not necessary if pthread_getthreadid_np is a libc stub
LDFLAGS+=	${LDFLAGS_${OPSYS}_${OSREL}}
LDFLAGS_FreeBSD_11.3=	-lpthread
LDFLAGS_FreeBSD_12.0=	-lpthread

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
X11_USE=		XORG=x11,xorgproto,xext,xfixes
X11_MESON_YES=		with_x11

.include <bsd.port.mk>

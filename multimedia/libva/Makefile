# $FreeBSD$

PORTNAME=	libva
PORTVERSION=	2.3.0
PORTREVISION=	3
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	cf11abe5e1b9.patch:-p1 # for media-driver 18.4+
PATCHFILES+=	62bad1239d8e.patch:-p1 # for mesa-libs 18.3+

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
RUN_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		autoreconf gmake libtool localbase pkgconfig tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=va
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	intel

LDFLAGS+=	-lpthread
# prevent types conflict: videodev2.h vs. drm.h
CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES

OPTIONS_DEFINE=	DEBUG WAYLAND X11
OPTIONS_DEFAULT=WAYLAND X11
OPTIONS_SUB=	yes

DEBUG_CFLAGS=		-D_DEBUG
DEBUG_CFLAGS_OFF=	-DNDEBUG

WAYLAND_CONFIGURE_ENABLE=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland

X11_CONFIGURE_ENABLE=	x11 glx
X11_USES=		gl
X11_USE=		GL=gl XORG=x11,xorgproto,xext,xfixes

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|$${libdir}/\(pkgconfig\)|${PREFIX}/libdata/\1|' \
		-e 's/"$$USE_X11:$$enable_glx" != "yes:no"/"$$USE_X11" != "no"/' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} '/^export VA_HEADER_/d' \
		${WRKSRC}/doc/Makefile.am
	${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/va/Makefile.am

.include <bsd.port.mk>

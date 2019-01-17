# $FreeBSD$

PORTNAME=	libva
PORTVERSION=	2.3.0
PORTREVISION=	4
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	cf11abe5e1b9.patch:-p1 # for media-driver 18.4+
PATCHFILES+=	62bad1239d8e.patch:-p1 # for mesa-libs 18.3+

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		autoreconf gmake libtool pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	intel
GNU_CONFIGURE=	yes
LDFLAGS+=	-lpthread # for pthread_getthreadid_np
INSTALL_TARGET=	install-strip

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
# V4L2 is unused since http://github.com/intel/libva/commit/70074679333c
	${REINPLACE_CMD} '/videodev2\.h/d' ${WRKSRC}/va/va_backend.h

.include <bsd.port.mk>

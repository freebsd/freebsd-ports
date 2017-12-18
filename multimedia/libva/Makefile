# $FreeBSD$

PORTNAME=	libva
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
RUN_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		autoreconf gmake libtool localbase pkgconfig tar:bzip2
USE_XORG=	glproto pciaccess x11 xext xfixes
USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=va
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	01org

LDFLAGS+=	-lpthread
# prevent types conflict: videodev2.h vs. drm.h
CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES

OPTIONS_DEFINE=	DEBUG WAYLAND
WAYLAND_DESC=	Support wayland protocol
OPTIONS_SUB=	yes

DEBUG_CFLAGS=		-D_DEBUG
DEBUG_CFLAGS_OFF=	-DNDEBUG

WAYLAND_CONFIGURE_ENABLE=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_BUILD_DEPENDS=	gsed:textproc/gsed

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|$${libdir}/\(pkgconfig\)|${PREFIX}/libdata/\1|' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} '/^export VA_HEADER_/d' \
		${WRKSRC}/doc/Makefile.am
	${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/va/Makefile.am

post-configure-WAYLAND-on: .SILENT
	${REINPLACE_CMD} -e 's|\(SED = \).*|\1${LOCALBASE}/bin/gsed|' \
		${WRKSRC}/va/wayland/Makefile

.include <bsd.port.mk>

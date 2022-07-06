PORTNAME=	wlvncc
PORTVERSION=	s20220706
CATEGORIES=	net

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland Native VNC Client

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm
LIB_DEPENDS=	liblzo2.so:archivers/lzo2 \
		libaml.so:devel/aml \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libavcodec.so:multimedia/ffmpeg \
		libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gl jpeg meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl gbm glesv2
USE_XORG=	pixman
GH_ACCOUNT=	any1
GH_TAGNAME=	81c9d84
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

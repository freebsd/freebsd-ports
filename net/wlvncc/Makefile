PORTNAME=	wlvncc
PORTVERSION=	s20250727
CATEGORIES=	net wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland Native VNC Client
WWW=		https://github.com/any1/wlvncc

LICENSE=	GPLv2+ ISCL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_ISCL=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
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
GH_TAGNAME=	860232f
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

PORTNAME=	droidcam
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	GNU/Linux/nix client for DroidCam
WWW=		https://github.com/dev47apps/droidcam

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libappindicator3.so:devel/libappindicator \
		libasound.so:audio/alsa-lib \
		libatk-1.0.so:accessibility/at-spi2-core \
		libcairo-gobject.so:graphics/cairo \
		libcairo.so:graphics/cairo \
		libdbusmenu-glib.so:devel/libdbusmenu \
		libgdk-3.so:x11-toolkits/gtk30 \
		libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2 \
		libgio-2.0.so:devel/glib20 \
		libglib-2.0.so:devel/glib20 \
		libgobject-2.0.so:devel/glib20 \
		libgtk-3.so:x11-toolkits/gtk30 \
		libharfbuzz.so:print/harfbuzz \
		libpango-1.0.so:x11-toolkits/pango \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libspeex.so:audio/speex \
		libturbojpeg.so:graphics/libjpeg-turbo \
		libusbmuxd-2.0.so:comms/libusbmuxd \
		libX11.so:x11/libX11 \
		libswscale.so:multimedia/ffmpeg
RUN_DEPENDS=	adb:devel/android-tools \
		ffmpeg:multimedia/ffmpeg \
		usbmuxd:comms/usbmuxd \
		webcamd:multimedia/webcamd

USES=		desktop-file-utils gettext-runtime gmake gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	dev47apps
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 pango
USE_XORG=	x11

PLIST_FILES=	bin/droidcam \
		bin/droidcam-cli \
		share/applications/droidcam.desktop \
		share/pixmaps/droidcam-icon.png

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/droidcam \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/droidcam-cli \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icon2.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/droidcam-icon.png
	${INSTALL_DATA} ${WRKSRC}/droidcam.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>

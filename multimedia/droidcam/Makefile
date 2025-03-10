PORTNAME=	droidcam
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.3
PORTREVISION=	3
CATEGORIES=	multimedia

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	GNU/Linux/nix client for DroidCam
WWW=		https://github.com/dev47apps/droidcam-linux-client

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
		libswscale.so:multimedia/ffmpeg \
		libturbojpeg.so:graphics/libjpeg-turbo \
		libusbmuxd-2.0.so:comms/libusbmuxd \
		libwayland-client.so:graphics/wayland \
		libX11.so:x11/libX11
RUN_DEPENDS=	adb:devel/android-tools \
		ffmpeg:multimedia/ffmpeg \
		usbmuxd:comms/usbmuxd \
		webcamd:multimedia/webcamd

USES=		desktop-file-utils gettext-runtime gmake gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	dev47apps
GH_PROJECT=	droidcam-linux-client
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 pango
USE_XORG=	x11

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-cli \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}-icon.png

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

pre-configure:
	${REINPLACE_CMD} -e 's,/opt/${PORTNAME}-icon.png,${PREFIX}/share/pixmaps/${PORTNAME}-icon.png,' \
		${WRKSRC}/src/${PORTNAME}.c \
		${WRKSRC}/${PORTNAME}.desktop
	${REINPLACE_CMD} -e 's,Exec=/usr/local/bin/${PORTNAME},${PREFIX}/bin/${PORTNAME},' \
		-e 's,TryExec=/usr/local/bin/${PORTNAME},${PREFIX}/bin/${PORTNAME},' \
		${WRKSRC}/${PORTNAME}.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}-cli \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icon2.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}-icon.png
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>

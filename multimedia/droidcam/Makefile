PORTNAME=	droidcam
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.4
CATEGORIES=	multimedia

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Turn your mobile device(s) into a wireless/usb webcam
WWW=		https://github.com/dev47apps/droidcam-linux-client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libappindicator3.so:devel/libappindicator \
		libasound.so:audio/alsa-lib \
		libdbusmenu-glib.so:devel/libdbusmenu \
		libspeex.so:audio/speex \
		libswscale.so:multimedia/ffmpeg \
		libturbojpeg.so:graphics/libjpeg-turbo \
		libusbmuxd-2.0.so:comms/libusbmuxd
RUN_DEPENDS=	adb:devel/android-tools \
		usbmuxd:comms/usbmuxd \
		webcamd:multimedia/webcamd

USES=		gmake gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	dev47apps
GH_PROJECT=	droidcam-linux-client
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 pango
USE_XORG=	x11

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-cli \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

post-patch:
	${REINPLACE_CMD} -e 's,/opt/${PORTNAME}-icon.png,${PREFIX}/share/pixmaps/${PORTNAME}.png,' \
		-e 's,/usr/local/bin/${PORTNAME},${PREFIX}/bin/${PORTNAME},' \
		${WRKSRC}/src/${PORTNAME}.c \
		${WRKSRC}/${PORTNAME}.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/${PORTNAME}-cli \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icon2.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>

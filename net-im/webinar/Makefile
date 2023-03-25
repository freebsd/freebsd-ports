# This port will not be packaged by the official FreeBSD build cluster, because
# its license doesn't permit redistribution.
#
# To build this port locally with minimal effort use
# cd <PORTSDIR>/net-im/webinar
# pkg install -A webcamd `make -V 'electron${ELECTRON_VERSION}'`
# make USE_PACKAGE_DEPENDS_ONLY=yes install clean

PORTNAME=	webinar
PORTVERSION=	1.0.11
CATEGORIES=	net-im net-p2p
# distfile is obtained by running "snap download webinar" on Linux
DISTNAME=	webinar_2
EXTRACT_SUFX=	.snap

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Platform for organizing online conferences
WWW=		https://webinar.ru/products/webinar/

LICENSE=	Proprietary
LICENSE_NAME=	Proprietary license with a small trial period
LICENSE_TEXT=	See https://webinar.ru/legal/license-agreement.pdf
LICENSE_PERMS=

DEPRECATED=	Requires EOLed electron18
EXPIRATION_DATE=	2023-04-24

EXTRACT_DEPENDS=	unsquashfs:sysutils/squashfs-tools
BUILD_DEPENDS=		electron${ELECTRON_VERSION}:devel/electron${ELECTRON_VERSION}
RUN_DEPENDS=		electron${ELECTRON_VERSION}:devel/electron${ELECTRON_VERSION} \
			webcamd>0:multimedia/webcamd

# All deps below are there only to please stage-qa

LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libsnappy.so:archivers/snappy \
		libopus.so:audio/opus \
		libdbus-1.so:devel/dbus \
		libnspr4.so:devel/nspr \
		libFLAC.so:audio/flac \
		libpci.so:devel/libpci \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libwebp.so:graphics/webp \
		libopenh264.so:multimedia/openh264 \
		libharfbuzz.so:print/harfbuzz \
		libexpat.so:textproc/expat2 \
		libnss3.so:security/nss \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence \
		libfontconfig.so:x11-fonts/fontconfig \
		libcups.so:print/cups

USES=		desktop-file-utils gettext-runtime gl gnome iconv:wchar_t jpeg \
		xorg

USE_GL=		gbm gl
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 libxslt pango
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xi xrandr xrender xtst

SUB_FILES=	webinar
NO_BUILD=	yes
STRIP=
UNSQUASHFS=	${LOCALBASE}/bin/unsquashfs

ELECTRON_VERSION=	18
ELECTRON_FILES=		chromedriver \
			libEGL.so \
			libGLESv2.so \
			libffmpeg.so \
			libvk_swiftshader.so \
			libvulkan.so \
			resources.pak \
			snapshot_blob.bin \
			v8_context_snapshot.bin

do-extract:
	${UNSQUASHFS} -dest ${WRKSRC} -no-xattrs ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-patch:
	${REINPLACE_CMD} -i '' -e 's|Icon=.*$$|Icon=webinar|' ${WRKSRC}/meta/gui/webinar.desktop

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/webinar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/meta/gui/webinar.desktop ${STAGEDIR}${DESKTOPDIR}/webinar.desktop
	${INSTALL_DATA} ${WRKSRC}/meta/gui/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/webinar.png

post-install:
	${RM} ${STAGEDIR}${DATADIR}/chrome-sandbox
	${RM} ${STAGEDIR}${DATADIR}/libvulkan.so.1
	${RM} -r ${STAGEDIR}${DATADIR}/usr/lib/
	${RM} -r ${STAGEDIR}${DATADIR}/lib/
	${RM} -r ${STAGEDIR}${DATADIR}/meta
	${FIND} ${STAGEDIR}${DATADIR} -type d -empty -delete
.for f in ${ELECTRON_FILES}
	${RM} ${STAGEDIR}${DATADIR}/${f}
	${LN} -s ${LOCALBASE}/share/electron${ELECTRON_VERSION}/${f} ${STAGEDIR}${DATADIR}/${f}
.endfor
# We have to copy the electron binary instead of symlinking
	${CP} ${LOCALBASE}/share/electron${ELECTRON_VERSION}/electron ${STAGEDIR}${DATADIR}/webinar

.include <bsd.port.mk>

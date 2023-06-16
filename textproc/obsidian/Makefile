# This port will not be packaged by the official FreeBSD build cluster, because
# its license doesn't permit redistribution.
#
# To build this port locally with minimal effort use
# cd <PORTSDIR>/textproc/obsidian
# pkg install -A `make -V 'electron${ELECTRON_VERSION}'`
# make USE_PACKAGE_DEPENDS_ONLY=yes install clean

PORTNAME=	obsidian
PORTVERSION=	1.3.5
CATEGORIES=	textproc
# Icon is taken from the Nix build recipe
# https://github.com/NixOS/nixpkgs/blob/de5448dab588ad41aef40f8c7c0c230981656698/pkgs/applications/misc/obsidian/default.nix#L31-L34
MASTER_SITES=	https://github.com/obsidianmd/obsidian-releases/releases/download/v${PORTVERSION}/ \
		https://forum.obsidian.md/uploads/default/original/1X/:icon
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		bf119bd48f748f4fd2d65f2d1bb05d3c806883b5.png:icon
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Powerful and extensible knowledge base application
WWW=		https://obsidian.md

LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_TEXT=	See https://obsidian.md/terms
LICENSE_PERMS=

BUILD_DEPENDS=	electron${ELECTRON_VERSION}:devel/electron${ELECTRON_VERSION}
RUN_DEPENDS=	electron${ELECTRON_VERSION}:devel/electron${ELECTRON_VERSION}

# All deps below are there only to please stage-qa

LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libsnappy.so:archivers/snappy \
		libopus.so:audio/opus \
		libdbus-1.so:devel/dbus \
		libicuuc.so:devel/icu \
		libevent.so:devel/libevent \
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
		libcups.so:print/cups \
		libasound.so:audio/alsa-lib

USES=		desktop-file-utils gettext-runtime gl gnome iconv jpeg xorg

USE_GL=		gbm gl glesv2
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 libxml2 libxslt
USE_XORG=	x11 xcb xcomposite xcursor xdamage xext xfixes xi xrandr \
		xrender xscrnsaver xtst

SUB_FILES=	obsidian
NO_BUILD=	yes
STRIP=

ELECTRON_VERSION=	24
ELECTRON_FILES=		chromedriver \
			libEGL.so \
			libGLESv2.so \
			libffmpeg.so \
			libvk_swiftshader.so \
			libvulkan.so \
			resources.pak \
			snapshot_blob.bin \
			v8_context_snapshot.bin

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/obsidian ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PATCHDIR}/obsidian.desktop ${STAGEDIR}${DESKTOPDIR}/obsidian.desktop
	${INSTALL_DATA} ${DISTDIR}/bf119bd48f748f4fd2d65f2d1bb05d3c806883b5.png ${STAGEDIR}${PREFIX}/share/pixmaps/obsidian.png

post-install:
	${RM} ${STAGEDIR}${DATADIR}/chrome-sandbox
	${RM} ${STAGEDIR}${DATADIR}/libvulkan.so.1
.for f in ${ELECTRON_FILES}
	${RM} ${STAGEDIR}${DATADIR}/${f}
	${LN} -s ${LOCALBASE}/share/electron${ELECTRON_VERSION}/${f} ${STAGEDIR}${DATADIR}/${f}
.endfor
# We have to copy the electron binary instead of symlinking
	${CP} ${LOCALBASE}/share/electron${ELECTRON_VERSION}/electron ${STAGEDIR}${DATADIR}/obsidian

.include <bsd.port.mk>

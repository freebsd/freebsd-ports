PORTNAME=	zotero
DISTVERSION=	5.0.96.3
CATEGORIES=	science deskutils
MASTER_SITES=	LOCAL/mikael
DISTFILES=	Zotero-${DISTVERSION}_FreeBSD-${ARCH}${EXTRACT_SUFX}
EXTRACT_ONLY=	Zotero-${DISTVERSION}_FreeBSD-${ARCH}${EXTRACT_SUFX}

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Reference management for bibliographic data and research materials

LICENSE=	AGPLv3

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	uses FreeBSD 13.x precompiled binaries
BROKEN_FreeBSD_12=	uses FreeBSD 13.x precompiled binaries

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libatspi.so:accessibility/at-spi2-core \
		libdbus-1.so:devel/dbus \
		libepoll-shim.so:devel/libepoll-shim \
		libepoxy.so:graphics/libepoxy \
		libevent.so:devel/libevent \
		libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libGLdispatch.so:graphics/libglvnd \
		libgraphite2.so:graphics/graphite2 \
		libharfbuzz.so:print/harfbuzz \
		libhunspell-1.7.so:textproc/hunspell \
		libnss3.so:security/nss \
		libpcre.so:devel/pcre \
		libplc4.so:devel/nspr \
		libpng16.so:graphics/png \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		desktop-file-utils gettext-runtime gl iconv jpeg gnome sqlite tar:xz xorg
USE_GL=		egl
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 gtk30 pango
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender xt
WRKSRC=		${WRKDIR}/Zotero_FreeBSD-${ARCH}

NO_BUILD=	yes

INSTALLDIR=	${STAGEDIR}/${LOCALBASE}/lib/${PORTNAME}

do-install:
	@${MKDIR} ${INSTALLDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR})
	${CP} ${INSTALLDIR}/zotero.desktop ${STAGEDIR}${PREFIX}/share/applications
	${LN} -sf ${PREFIX}/lib/zotero/chrome/icons/default/default48.png ${STAGEDIR}${PREFIX}/share/pixmaps/zotero.png
	${RLN} ${INSTALLDIR}/zotero ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

PORTNAME=	zotero
DISTVERSION=	10.0.8
CATEGORIES=	science deskutils
MASTER_SITES=	LOCAL/mikael
DISTFILES=	Zotero-${DISTVERSION}_FreeBSD-${ARCH}${EXTRACT_SUFX}
EXTRACT_ONLY=	Zotero-${DISTVERSION}_FreeBSD-${ARCH}${EXTRACT_SUFX}

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Reference management for bibliographic data and research materials
WWW=		https://www.zotero.org/

LICENSE=	AGPLv3

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	uses FreeBSD 14.x precompiled binaries

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libaom.so:multimedia/aom \
		libdav1d.so:multimedia/dav1d \
		libevent.so:devel/libevent \
		libffi.so:devel/libffi \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libpng.so:graphics/png \
		libpixman-1.so:x11/pixman \
		libvpx.so:multimedia/libvpx \
		libwebp.so:graphics/webp \
		libdbus-1.so:devel/dbus \
		libatk-1.0.so:accessibility/at-spi2-core \
		libcairo.so:graphics/cairo \
		libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2 \
		libglib-2.0.so:devel/glib20 \
		libgtk-3.so:x11-toolkits/gtk30 \
		libharfbuzz.so:print/harfbuzz \
		libpango-1.0.so:x11-toolkits/pango \
		libjpeg.so:graphics/jpeg-turbo \
		libutil.so.9:misc/compat14x

USES=		desktop-file-utils gettext-runtime gl iconv jpeg gnome tar:xz xorg
USE_GL=		egl
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk20 gtk30 pango
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender xt
WRKSRC=		${WRKDIR}/Zotero_FreeBSD-${ARCH}

NO_BUILD=	yes

INSTALLDIR=	${STAGEDIR}/${LOCALBASE}/lib/${PORTNAME}

do-install:
	@${MKDIR} ${INSTALLDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR})
	${CP} ${INSTALLDIR}/zotero.desktop ${STAGEDIR}${PREFIX}/share/applications
	${LN} -sf ${PREFIX}/lib/zotero/icons/icon128.png ${STAGEDIR}${PREFIX}/share/pixmaps/zotero.png
	${RLN} ${INSTALLDIR}/zotero ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

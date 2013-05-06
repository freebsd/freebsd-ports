# $FreeBSD$

PORTNAME=	freetuxtv
PORTVERSION=	0.6.5
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	nemysis@gmx.ch
COMMENT=	WebTV player based on GTK2+ and LibVLC

LICENSE=	GPLv3

LIB_DEPENDS=	vlc:${PORTSDIR}/multimedia/vlc \
		dbus-glib:${PORTSDIR}/devel/dbus-glib \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		curl:${PORTSDIR}/ftp/curl \
		notify:${PORTSDIR}/devel/libnotify \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb

USE_GNOME=	glib20 gtk20
USE_XORG=	pixman x11 xau xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		pkgconfig iconv
INSTALLS_ICONS=	yes

CONFIGURE_ARGS+=--with-gtk=2.0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>

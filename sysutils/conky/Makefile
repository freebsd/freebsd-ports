# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	conky
PORTVERSION=	1.9.0
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT?=	Advanced, highly configurable system monitor for X11

CONFLICTS?=	conky-awesome-[0-9]*
SLAVEDIRS=	sysutils/conky-awesome

USES=		cpe gmake iconv localbase pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-portmon \
			--disable-hddtemp \
			--disable-alsa \
			--disable-bmpx \
			--disable-iostats

PLIST_FILES=	bin/conky man/man1/conky.1.gz
PORTEXAMPLES=	conkyrc.sample
PORTDOCS=	README AUTHORS ChangeLog TODO NEWS \
		docs.html variables.html config_settings.html

OPTIONS_DEFINE=	APCUPSD AUDACIOUS INOTIFY LUA METAR MOC MPD NCURSES RSS \
		X11 XMMS2 XOAP

OPTIONS_GROUP?=	X11
OPTIONS_GROUP_X11=	ARGB DOUBLE_BUFFER IMLIB2 XFT LUA_CAIRO LUA_IMLIB2
OPTIONS_DEFAULT?=	X11 ARGB DOUBLE_BUFFER XFT

APCUPSD_DESC=		Monitor APCUPSD
APCUPSD_CONFIGURE_ENABLE=apcupsd

ARGB_DESC=		Use an ARGB visual to draw on X11
ARGB_CONFIGURE_ENABLE=	argb
ARGB_IMPLIES=		X11

AUDACIOUS_DESC=		Control Audacious sound player
AUDACIOUS_CONFIGURE_ENABLE=audacious
AUDACIOUS_LIB_DEPENDS=	libaudclient.so:multimedia/audacious

DOUBLE_BUFFER_DESC=	X11 double buffering
DOUBLE_BUFFER_CONFIGURE_ENABLE=double-buffer
DOUBLE_BUFFER_IMPLIES=	X11

IMLIB2_CONFIGURE_ENABLE=imlib2
IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_IMPLIES=		X11

INOTIFY_DESC=		Monitor file changes via Inotify
INOTIFY_CONFIGURE_ENABLE=inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify

LUA_USES=		lua:51
LUA_CONFIGURE_ENABLE=	lua
LUA_LIB_DEPENDS=	libtolua++-5.1.so:lang/tolua++

LUA_CAIRO_DESC=		Lua-Cairo binding
LUA_CAIRO_CONFIGURE_ENABLE=lua-cairo
LUA_CAIRO_USE=		gnome=cairo
LUA_CAIRO_IMPLIES=	LUA X11

LUA_IMLIB2_DESC=	Lua-Imlib2 binding
LUA_IMLIB2_CONFIGURE_ENABLE=lua-imlib2
LUA_IMLIB2_IMPLIES=	IMLIB2 LUA X11

METAR_DESC=		Display METAR weather reports
METAR_CONFIGURE_ENABLE=	weather-metar
METAR_LIB_DEPENDS=	libcurl.so:ftp/curl

MOC_DESC=		Control MOC (Music On Console)
MOC_CONFIGURE_ENABLE=	moc

MPD_DESC=		Control MPD (Music Player Daemon)
MPD_CONFIGURE_ENABLE=	mpd

NCURSES_DESC=		Use ncurses to draw on terminals
NCURSES_CONFIGURE_ENABLE=ncurses

RSS_DESC=		Display RSS feeds
RSS_CONFIGURE_ENABLE=	rss
RSS_USE=		gnome=glib20,libxml2
RSS_LIB_DEPENDS=	libcurl.so:ftp/curl

X11_USE=		xorg=x11,xext,xdamage,xfixes
X11_CONFIGURE_ENABLE=	x11 own-window
X11_VARS=		EXAMPLE_CONF_FILE=${WRKSRC}/data/conky.conf
X11_VARS_OFF=		EXAMPLE_CONF_FILE=${WRKSRC}/data/conky_no_x11.conf

XFT_CONFIGURE_ENABLE=	xft
XFT_USE=		xorg=xft
XFT_IMPLIES=		X11

XMMS2_DESC=		Control XMMS2 media player
XMMS2_CONFIGURE_ENABLE=	xmms2
XMMS2_LIB_DEPENDS=	libxmmsclient.so:audio/xmms2

XOAP_DESC=		Display XOAP weather reports
XOAP_CONFIGURE_ENABLE=	weather-xoap
XOAP_LIB_DEPENDS=	libcurl.so:ftp/curl
XOAP_USE=		gnome=libxml2

post-patch:
	@${REINPLACE_CMD} -e 's,lua5\.1,lua-5.1,g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,imlib_context_disconnect_display();,,g' \
		${WRKSRC}/src/imlib2.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/conky ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/conky.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLE_CONF_FILE} ${STAGEDIR}${EXAMPLESDIR}/conkyrc.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README AUTHORS ChangeLog TODO NEWS
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in docs.html variables.html config_settings.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

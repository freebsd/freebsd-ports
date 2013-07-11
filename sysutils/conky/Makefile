# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	conky
PORTVERSION=	1.9.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	An advanced, highly configurable system monitor for X

CONFLICTS?=	conky-awesome-[0-9]*
SLAVEDIRS=	sysutils/conky-awesome

USES=		pkgconfig iconv
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--disable-portmon \
			--disable-hddtemp \
			--disable-alsa \
			--disable-bmpx \
			--disable-iostats
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		conky.1
PLIST_FILES=	bin/conky
PORTEXAMPLES=	conkyrc.sample
PORTDOCS=	README AUTHORS ChangeLog TODO NEWS \
		docs.html variables.html config_settings.html

OPTIONS_DEFINE=	APCUPSD AUDACIOUS INOTIFY LUA METAR MOC MPD NCURSES RSS \
		X11 XMMS2 XOAP

OPTIONS_GROUP?=	X11
OPTIONS_GROUP_X11=	ARGB DOUBLE_BUFFER IMLIB2 XFT LUA_CAIRO LUA_IMLIB2
OPTIONS_DEFAULT?=	X11 ARGB DOUBLE_BUFFER

ARGB_DESC=		Use an ARGB visual to draw on X11
APCUPSD_DESC=		Monitor APCUPSD
AUDACIOUS_DESC=		Control Audacious sound player
DOUBLE_BUFFER_DESC=	Enable X11 double buffering
INOTIFY_DESC=		Monitor file changes via Inotify
LUA_CAIRO_DESC=		Lua-Cairo binding
LUA_IMLIB2_DESC=	Lua-Imlib2 binding
METAR_DESC=		Display METAR weather reports
MOC_DESC=		Control MOC (Music On Console)
MPD_DESC=		Control MPD (Music Player Daemon)
NCURSES_DESC=		Use ncurses to draw on terminals
RSS_DESC=		Display RSS feeds
XMMS2_DESC=		Control XMMS2 media player
XOAP_DESC=		Display XOAP weather reports

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARGB} || ${PORT_OPTIONS:MDOUBLE_BUFFER} || ${PORT_OPTIONS:MIMLIB2} || ${PORT_OPTIONS:MLUA_CAIRO} || ${PORT_OPTIONS:MLUA_IMLIB2} || ${PORT_OPTIONS:MXFT} || ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xext xdamage
CONFIGURE_ARGS+=	--enable-x11 --enable-own-window
EXAMPLE_CONF_FILE=	${WRKSRC}/data/conky.conf
.else
CONFIGURE_ARGS+=	--disable-x11 --disable-own-window
EXAMPLE_CONF_FILE=	${WRKSRC}/data/conky_no_x11.conf
.endif

.if ${PORT_OPTIONS:MAPCUPSD}
CONFIGURE_ARGS+=	--enable-apcupsd
.else
CONFIGURE_ARGS+=	--disable-apcupsd
.endif

.if ${PORT_OPTIONS:MARGB}
CONFIGURE_ARGS+=	--enable-argb
.else
CONFIGURE_ARGS+=	--disable-argb
.endif

.if ${PORT_OPTIONS:MAUDACIOUS}
LIB_DEPENDS+=		audclient:${PORTSDIR}/multimedia/audacious
CONFIGURE_ARGS+=	--enable-audacious
.else
CONFIGURE_ARGS+=	--disable-audacious
.endif

.if ${PORT_OPTIONS:MDOUBLE_BUFFER}
CONFIGURE_ARGS+=	--enable-double-buffer
.else
CONFIGURE_ARGS+=	--disable-double-buffer
.endif

.if ${PORT_OPTIONS:MIMLIB2} || ${PORT_OPTIONS:MLUA_IMLIB2}
LIB_DEPENDS+=		Imlib2:${PORTSDIR}/graphics/imlib2
CONFIGURE_ARGS+=	--enable-imlib2
.else
CONFIGURE_ARGS+=	--disable-imlib2
.endif

.if ${PORT_OPTIONS:MINOTIFY}
LIB_DEPENDS+=		inotify:${PORTSDIR}/devel/libinotify
CONFIGURE_ARGS+=	--enable-inotify
.else
CONFIGURE_ARGS+=	--disable-inotify
.endif

.if ${PORT_OPTIONS:MLUA_CAIRO}
LIB_DEPENDS+=		cairo:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS+=		tolua++-5.1:${PORTSDIR}/lang/tolua++
RUN_DEPENDS+=		tolua++-5.1:${PORTSDIR}/lang/tolua++
CONFIGURE_ARGS+=	--enable-lua-cairo
.else
CONFIGURE_ARGS+=	--disable-lua-cairo
.endif

.if ${PORT_OPTIONS:MLUA_IMLIB2}
BUILD_DEPENDS+=		tolua++-5.1:${PORTSDIR}/lang/tolua++
RUN_DEPENDS+=		tolua++-5.1:${PORTSDIR}/lang/tolua++
CONFIGURE_ARGS+=	--enable-lua-imlib2
.else
CONFIGURE_ARGS+=	--disable-lua-imlib2
.endif

.if ${PORT_OPTIONS:MLUA} || ${PORT_OPTIONS:MLUA_CAIRO} || ${PORT_OPTIONS:MLUA_IMLIB2}
USE_LUA=		5.1+
CONFIGURE_ARGS+=	--enable-lua
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

.if ${PORT_OPTIONS:MMETAR}
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--enable-weather-metar
.else
CONFIGURE_ARGS+=	--disable-weather-metar
.endif

.if ${PORT_OPTIONS:MMOC}
CONFIGURE_ARGS+=	--enable-moc
.else
CONFIGURE_ARGS+=	--disable-moc
.endif

.if ${PORT_OPTIONS:MMPD}
CONFIGURE_ARGS+=	--enable-mpd
.else
CONFIGURE_ARGS+=	--disable-mpd
.endif

.if ${PORT_OPTIONS:MNCURSES}
CONFIGURE_ARGS+=	--enable-ncurses
.else
CONFIGURE_ARGS+=	--disable-ncurses
.endif

.if ${PORT_OPTIONS:MRSS}
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl \
			xml2:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--enable-rss
USE_GNOME+=		glib20
.else
CONFIGURE_ARGS+=	--disable-rss
.endif

.if ${PORT_OPTIONS:MXFT}
LIB_DEPENDS+=		Xft:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-xft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if ${PORT_OPTIONS:MXMMS2}
LIB_DEPENDS+=		xmmsclient:${PORTSDIR}/audio/xmms2
CONFIGURE_ARGS+=	--enable-xmms2
.else
CONFIGURE_ARGS+=	--disable-xmms2
.endif

.if ${PORT_OPTIONS:MXOAP}
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl \
			xml2:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--enable-weather-xoap
.else
CONFIGURE_ARGS+=	--disable-weather-xoap
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,lua5\.1,lua-5.1,g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,imlib_context_disconnect_display();,,g' \
		${WRKSRC}/src/imlib2.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/conky ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/conky.1 ${PREFIX}/man/man1

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLE_CONF_FILE} ${EXAMPLESDIR}/conkyrc.sample
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in README AUTHORS ChangeLog TODO NEWS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in docs.html variables.html config_settings.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

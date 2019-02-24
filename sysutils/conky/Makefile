# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	conky
PORTVERSION=	1.11.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	madpilot@FreeBSD.org
COMMENT?=	Advanced, highly configurable system monitor for X11

LIB_DEPENDS=	libinotify.so:devel/libinotify
BUILD_DEPENDS=	db2x_xsltproc:textproc/docbook2X \
		docbook-xsl>=0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt

USES=		cpe cmake:noninja compiler:c++11-lib gettext-runtime iconv \
		localbase lua:53 pkgconfig tar:bzip2

CMAKE_ARGS+=	-DBUILD_PORT_MONITORS:BOOL=false \
		-DBUILD_IBM:BOOL=false \
		-DBUILD_HDDTEMP:BOOL=false \
		-DBUILD_IOSTATS:BOOL=false \
		-DBUILD_AUDACIOUS:BOOL=false
CONFLICTS?=	conky-awesome-[0-9]*

SLAVEDIRS=	sysutils/conky-awesome
PLIST_FILES=	bin/conky man/man1/conky.1.gz
PORTEXAMPLES=	conky.conf conky_no_x11.conf convert.lua
PORTDOCS=	html/config_settings.html html/docs.html html/lua.html html/variables.html

USE_GITHUB=	yes
GH_ACCOUNT=	brndnmtthws

OPTIONS_DEFINE=	APCUPSD CURL DOCS EXAMPLES IPV6 METAR MOC MPD NCURSES RSS \
		X11 XMMS2 XOAP

OPTIONS_GROUP?=	X11
OPTIONS_GROUP_X11=	ARGB DOUBLE_BUFFER IMLIB2 XFT XINERAMA LUA_CAIRO LUA_IMLIB2 LUA_RSVG
OPTIONS_DEFAULT?=	X11 ARGB DOUBLE_BUFFER XFT

APCUPSD_DESC=		Monitor APCUPSD
APCUPSD_CMAKE_BOOL=	BUILD_APCUPSD

ARGB_DESC=		Use an ARGB visual to draw on X11
ARGB_CMAKE_BOOL=	BUILD_ARGB
ARGB_IMPLIES=		X11

CURL_CMAKE_BOOL=	BUILD_CURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

DOUBLE_BUFFER_DESC=	X11 double buffering
DOUBLE_BUFFER_CMAKE_BOOL=BUILD_XDBE
DOUBLE_BUFFER_IMPLIES=	X11

IMLIB2_CMAKE_BOOL=	BUILD_IMLIB2
IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_IMPLIES=		X11

IPV6_CMAKE_BOOL=	BUILD_IPV6

LUA_CAIRO_DESC=		Lua-Cairo binding
LUA_CAIRO_CMAKE_BOOL=	BUILD_LUA_CAIRO
LUA_CAIRO_USE=		gnome=cairo
LUA_CAIRO_PLIST_FILES=	lib/conky/libcairo.so
LUA_CAIRO_IMPLIES=	X11

LUA_IMLIB2_DESC=	Lua-Imlib2 binding
LUA_IMLIB2_CMAKE_BOOL=	BUILD_LUA_IMLIB2
LUA_IMLIB2_PLIST_FILES=	lib/conky/libimlib2.so
LUA_IMLIB2_IMPLIES=	IMLIB2 X11

LUA_RSVG_DESC=		Lua-rsvg binding
LUA_RSVG_CMAKE_BOOL=	BUILD_LUA_RSVG
LUA_RSVG_USE=		gnome=librsvg2
LUA_RSVG_PLIST_FILES=	lib/conky/librsvg.so
LUA_RSVG_IMPLIES=	X11

METAR_DESC=		Display METAR weather reports
METAR_CMAKE_BOOL=	BUILD_WEATHER_METAR
METAR_IMPLIES=		CURL

MOC_DESC=		Control MOC (Music On Console)
MOC_CMAKE_BOOL=		BUILD_MOC

MPD_DESC=		Control MPD (Music Player Daemon)
MPD_CMAKE_BOOL=		BUILD_MPD

NCURSES_DESC=		Use ncurses to draw on terminals
NCURSES_CMAKE_BOOL=	BUILD_NCURSES
NCURSES_USES=		ncurses:port

RSS_DESC=		Display RSS feeds
RSS_CMAKE_BOOL=		BUILD_RSS
RSS_USE=		gnome=glib20,libxml2
RSS_IMPLIES=		CURL

X11_USE=		xorg=x11,xext,xdamage,xfixes
X11_CMAKE_BOOL=		BUILD_X11 OWN_WINDOW
X11_VARS=		EXAMPLE_CONF_FILE=${WRKSRC}/data/conky.conf
X11_VARS_OFF=		EXAMPLE_CONF_FILE=${WRKSRC}/data/conky_no_x11.conf

XFT_CMAKE_BOOL=		BUILD_XFT
XFT_USE=		xorg=xft
XFT_IMPLIES=		X11

XINERAMA_CMAKE_BOOL=	BUILD_XINERAMA
XINERAMA_USE=		xorg=xinerama
XINERAMA_IMPLIES=	X11

XMMS2_DESC=		Control XMMS2 media player
XMMS2_CMAKE_BOOL=	BUILD_XMMS2
XMMS2_LIB_DEPENDS=	libxmmsclient.so:audio/xmms2

XOAP_DESC=		Display XOAP weather reports
XOAP_CMAKE_BOOL=	BUILD_WEATHER_XOAP
XOAP_IMPLIES=		CURL METAR
XOAP_USE=		gnome=libxml2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUA_CAIRO} && ${PORT_OPTIONS:MLUA_IMLIB2}
PLIST_FILES+=		lib/conky/libcairo_imlib2_helper.so
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/^#\(set(RELEASE true\)/\1/' \
		-e 's/-D_POSIX_C_SOURCE=200809L/& -D__BSD_VISIBLE=1 -D_XOPEN_SOURCE=700/' \
		${WRKSRC}/cmake/Conky.cmake
	@${REINPLACE_CMD} -e 's,^set(INCLUDE_SEARCH_PATH \(.*\)),set(INCLUDE_SEARCH_PATH \1 ${LUA_INCDIR}),' \
		-e 's/ -lbsd/ -lintl -linotify/' \
		${WRKSRC}/cmake/ConkyPlatformChecks.cmake
	@${REINPLACE_CMD} -e 's,LOCALBASE,${LOCALBASE},' \
		${WRKSRC}/doc/docgen.sh

post-build:
	(cd ${WRKSRC}/doc && ${SH} docgen.sh)

.include <bsd.port.mk>

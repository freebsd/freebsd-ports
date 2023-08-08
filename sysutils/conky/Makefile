PORTNAME=	conky
PORTVERSION=	1.19.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	madpilot@FreeBSD.org
COMMENT?=	Advanced, highly configurable system monitor for X11
WWW=		https://github.com/brndnmtthws/conky

LIB_DEPENDS=	libinotify.so:devel/libinotify
BUILD_DEPENDS=	gsed:textproc/gsed

USES=		cmake compiler:c++11-lib cpe gettext-runtime iconv \
		localbase:ldflags lua:53 pkgconfig tar:bzip2

CMAKE_ARGS=	-DAPP_SED=${LOCALBASE}/bin/gsed \
		-DBUILD_AUDACIOUS:BOOL=false \
		-DBUILD_HDDTEMP:BOOL=false \
		-DBUILD_IBM:BOOL=false \
		-DBUILD_IOSTATS:BOOL=false \
		-DBUILD_PORT_MONITORS:BOOL=false
CONFLICTS?=	conky-awesome

SLAVEDIRS=	sysutils/conky-awesome
PLIST_FILES=	bin/conky
PORTEXAMPLES=	conky.conf conky_no_x11.conf convert.lua
PORTDOCS=	config_settings.yaml lua.yaml variables.yaml

USE_GITHUB=	yes
GH_ACCOUNT=	brndnmtthws

OPTIONS_DEFINE=	APCUPSD CURL DOCS EXAMPLES IPV6 MANPAGES METAR MOC MPD NCURSES \
		RSS WAYLAND X11 XOAP

OPTIONS_GROUP?=		X11
OPTIONS_GROUP_X11=	ARGB DOUBLE_BUFFER IMLIB2 LUA_CAIRO LUA_IMLIB2 LUA_RSVG \
			MOUSE_EVENTS XFT XINERAMA
OPTIONS_DEFAULT?=	ARGB DOUBLE_BUFFER LUA_CAIRO MANPAGES MOUSE_EVENTS \
			WAYLAND X11 XFT

APCUPSD_DESC=		Monitor APCUPSD
APCUPSD_CMAKE_BOOL=	BUILD_APCUPSD

ARGB_DESC=		Use an ARGB visual to draw on X11
ARGB_CMAKE_BOOL=	BUILD_ARGB
ARGB_IMPLIES=		X11

CURL_CMAKE_BOOL=	BUILD_CURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

DOUBLE_BUFFER_DESC=		X11 double buffering
DOUBLE_BUFFER_CMAKE_BOOL=	BUILD_XDBE
DOUBLE_BUFFER_IMPLIES=		X11

IMLIB2_CMAKE_BOOL=	BUILD_IMLIB2
IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_IMPLIES=		X11
IMLIB2_USE=		XORG=ice,sm

IPV6_CMAKE_BOOL=	BUILD_IPV6

LUA_CAIRO_DESC=		Lua-Cairo binding
LUA_CAIRO_CMAKE_BOOL=	BUILD_LUA_CAIRO
LUA_CAIRO_USES=		gnome
LUA_CAIRO_USE=		GNOME=cairo
LUA_CAIRO_PLIST_FILES=	lib/conky/libcairo.so
LUA_CAIRO_IMPLIES=	X11

LUA_IMLIB2_DESC=	Lua-Imlib2 binding
LUA_IMLIB2_CMAKE_BOOL=	BUILD_LUA_IMLIB2
LUA_IMLIB2_PLIST_FILES=	lib/conky/libimlib2.so
LUA_IMLIB2_IMPLIES=	IMLIB2 X11

LUA_RSVG_DESC=		Lua-rsvg binding
LUA_RSVG_CMAKE_BOOL=	BUILD_LUA_RSVG
LUA_RSVG_USES=		gnome
LUA_RSVG_USE=		GNOME=librsvg2
LUA_RSVG_PLIST_FILES=	lib/conky/librsvg.so
LUA_RSVG_IMPLIES=	X11

METAR_DESC=		Display METAR weather reports
METAR_CMAKE_BOOL=	BUILD_WEATHER_METAR
METAR_IMPLIES=		CURL

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
			pandoc:textproc/hs-pandoc
MANPAGES_USES=		python:build
MANPAGES_CMAKE_BOOL=	BUILD_DOCS
MANPAGES_PLIST_FILES=	man/man1/conky.1.gz

MOC_DESC=	Control MOC (Music On Console)
MOC_CMAKE_BOOL=	BUILD_MOC

MOUSE_EVENTS_DESC=		Support generating mouse events
MOUSE_EVENTS_CMAKE_BOOL=	BUILD_MOUSE_EVENTS
MOUSE_EVENTS_IMPLIES=		X11

MPD_DESC=	Control MPD (Music Player Daemon)
MPD_CMAKE_BOOL=	BUILD_MPD

NCURSES_DESC=		Use ncurses to draw on terminals
NCURSES_CMAKE_BOOL=	BUILD_NCURSES
NCURSES_USES=		ncurses:port

RSS_DESC=	Display RSS feeds
RSS_CMAKE_BOOL=	BUILD_RSS
RSS_USES=	gnome
RSS_USE=	GNOME=glib20,libxml2
RSS_IMPLIES=	CURL

WAYLAND_CATEGORIES=	wayland
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.13:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
			libfontconfig.so:x11-fonts/fontconfig \
			libwayland-client.so:graphics/wayland
WAYLAND_USES=		gnome
WAYLAND_USE=		GNOME=cairo,pango
WAYLAND_CMAKE_BOOL=	BUILD_WAYLAND
WAYLAND_LDFLAGS=	-Wl,--as-needed # pangoft2 deps: glib20, freetype2, harfbuzz

X11_USES=	xorg
X11_USE=	XORG=x11,xdamage,xext,xfixes
X11_CMAKE_BOOL=	BUILD_X11 OWN_WINDOW
X11_VARS=	EXAMPLE_CONF_FILE=${WRKSRC}/data/conky.conf
X11_VARS_OFF=	EXAMPLE_CONF_FILE=${WRKSRC}/data/conky_no_x11.conf

XFT_CMAKE_BOOL=	BUILD_XFT
XFT_USE=	XORG=xft
XFT_IMPLIES=	X11

XINERAMA_CMAKE_BOOL=	BUILD_XINERAMA
XINERAMA_USE=		XORG=xinerama
XINERAMA_IMPLIES=	X11

XOAP_DESC=		Display XOAP weather reports
XOAP_CMAKE_BOOL=	BUILD_WEATHER_XOAP
XOAP_IMPLIES=		CURL METAR
XOAP_USES=		gnome
XOAP_USE=		GNOME=libxml2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUA_CAIRO} && ${PORT_OPTIONS:MLUA_IMLIB2}
PLIST_FILES+=	lib/conky/libcairo_imlib2_helper.so
.endif

# disable apm on non-x86 archs
.if ${ARCH} != amd64 && ${ARCH} != i386
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src_CMakeLists.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^set(INCLUDE_SEARCH_PATH \(.*\)),set(INCLUDE_SEARCH_PATH \1 ${LUA_INCDIR}),' \
		${WRKSRC}/cmake/ConkyPlatformChecks.cmake

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

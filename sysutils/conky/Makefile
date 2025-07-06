PORTNAME=	conky
PORTVERSION=	1.22.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	fernape@FreeBSD.org
COMMENT?=	Advanced, highly configurable system monitor for X11
WWW=		https://github.com/brndnmtthws/conky

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	gperf:devel/gperf \
		gsed:textproc/gsed
LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		cmake compiler:c++11-lib cpe gettext-runtime iconv \
		localbase:ldflags lua:53 pkgconfig tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	brndnmtthws

CMAKE_ARGS=	-DAPP_SED=${LOCALBASE}/bin/gsed \
		-DBUILD_AUDACIOUS:BOOL=false \
		-DBUILD_HDDTEMP:BOOL=false \
		-DBUILD_IBM:BOOL=false \
		-DBUILD_IOSTATS:BOOL=false \
		-DBUILD_PORT_MONITORS:BOOL=false
CONFLICTS?=	conky-awesome

SLAVEDIRS=	sysutils/conky-awesome
PLIST_FILES=	bin/conky
PORTDOCS=	config_settings.yaml lua.yaml variables.yaml
PORTEXAMPLES=	conky.conf conky_no_x11.conf convert.lua

OPTIONS_DEFINE=	APCUPSD CURL DOCS EXAMPLES IPV6 MANPAGES METAR MOC MPD NCURSES \
		RSS WAYLAND X11 XOAP

OPTIONS_DEFAULT?=	ARGB DOUBLE_BUFFER IMLIB2 LUA_CAIRO LUA_IMLIB2 \
			MANPAGES MOUSE_EVENTS WAYLAND X11 XFT
OPTIONS_GROUP?=		X11
OPTIONS_GROUP_X11=	ARGB DOUBLE_BUFFER IMLIB2 LUA_CAIRO LUA_IMLIB2 LUA_RSVG \
			MOUSE_EVENTS XFT XINERAMA

APCUPSD_DESC=		Monitor APCUPSD
ARGB_DESC=		Use an ARGB visual to draw on X11
DOUBLE_BUFFER_DESC=	X11 double buffering
LUA_CAIRO_DESC=		Lua-Cairo binding
LUA_IMLIB2_DESC=	Lua-Imlib2 binding
LUA_RSVG_DESC=		Lua-rsvg binding
METAR_DESC=		Display METAR weather reports
MOC_DESC=		Control MOC (Music On Console)
MOUSE_EVENTS_DESC=	Support generating mouse events
MPD_DESC=		Control MPD (Music Player Daemon)
NCURSES_DESC=		Use ncurses to draw on terminals
RSS_DESC=		Display RSS feeds
XOAP_DESC=		Display XOAP weather reports

APCUPSD_CMAKE_BOOL=	BUILD_APCUPSD

ARGB_IMPLIES=		X11
ARGB_CMAKE_BOOL=	BUILD_ARGB

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CMAKE_BOOL=	BUILD_CURL

DOUBLE_BUFFER_IMPLIES=		X11
DOUBLE_BUFFER_CMAKE_BOOL=	BUILD_XDBE

IMLIB2_IMPLIES=		X11
IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_USE=		XORG=ice,sm
IMLIB2_CMAKE_BOOL=	BUILD_IMLIB2

IPV6_CMAKE_BOOL=	BUILD_IPV6

LUA_CAIRO_IMPLIES=	X11
LUA_CAIRO_USES=		gnome
LUA_CAIRO_USE=		GNOME=cairo
LUA_CAIRO_CMAKE_BOOL=	BUILD_LUA_CAIRO
LUA_CAIRO_PLIST_FILES=	lib/conky/libcairo.so \
			lib/conky/libcairo_xlib.so

LUA_IMLIB2_IMPLIES=	IMLIB2 X11
LUA_IMLIB2_CMAKE_BOOL=	BUILD_LUA_IMLIB2
LUA_IMLIB2_PLIST_FILES=	lib/conky/libimlib2.so

LUA_RSVG_IMPLIES=	X11
LUA_RSVG_USES=		gnome
LUA_RSVG_USE=		GNOME=librsvg2
LUA_RSVG_CMAKE_BOOL=	BUILD_LUA_RSVG
LUA_RSVG_PLIST_FILES=	lib/conky/librsvg.so

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
			pandoc:textproc/hs-pandoc
MANPAGES_USES=		python:build
MANPAGES_CMAKE_BOOL=	BUILD_DOCS
MANPAGES_PLIST_FILES=	share/man/man1/conky.1.gz

METAR_IMPLIES=		CURL
METAR_CMAKE_BOOL=	BUILD_WEATHER_METAR

MOC_CMAKE_BOOL=	BUILD_MOC

MOUSE_EVENTS_IMPLIES=		X11
MOUSE_EVENTS_CMAKE_BOOL=	BUILD_MOUSE_EVENTS

MPD_CMAKE_BOOL=	BUILD_MPD

NCURSES_USES=		ncurses:port
NCURSES_CMAKE_BOOL=	BUILD_NCURSES

RSS_IMPLIES=	CURL
RSS_USES=	gnome
RSS_USE=	GNOME=libxml2
RSS_CMAKE_BOOL=	BUILD_RSS

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
X11_USE=	XORG=x11,xdamage,xext,xfixes,xi
X11_CMAKE_BOOL=	BUILD_X11 OWN_WINDOW

XFT_IMPLIES=	X11
XFT_USE=	XORG=xft
XFT_CMAKE_BOOL=	BUILD_XFT

XINERAMA_IMPLIES=	X11
XINERAMA_USE=		XORG=xinerama
XINERAMA_CMAKE_BOOL=	BUILD_XINERAMA

XOAP_IMPLIES=		CURL METAR
XOAP_USES=		gnome
XOAP_USE=		GNOME=libxml2
XOAP_CMAKE_BOOL=	BUILD_WEATHER_XOAP

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

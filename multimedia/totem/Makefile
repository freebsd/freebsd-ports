# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/totem/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	totem
PORTVERSION=	3.14.1
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gstreamer-based video player for the GNOME 3 Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		appdata-tools>=0:${PORTSDIR}/devel/appdata-tools \
		itstool:${PORTSDIR}/textproc/itstool \
		grilo-plugins>=0:${PORTSDIR}/net/grilo-plugins
LIB_DEPENDS=	libgdata.so:${PORTSDIR}/devel/libgdata \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libpeas-1.0.so:${PORTSDIR}/devel/libpeas \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		gnome-settings-daemon>=2.91.0:${PORTSDIR}/sysutils/gnome-settings-daemon \
		gnome-icon-theme-symbolic>=2.91.0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic \
		grilo-plugins>=0:${PORTSDIR}/net/grilo-plugins \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:${PORTSDIR}/devel/py3-libpeas

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		python:3 shebangfix tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack introspection:build \
		libxml2 nautilus3 py3gobject3
USE_XORG=	x11 xproto xtst ice sm
USE_GSTREAMER1=	core good bad soup ugly
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lXrandr"
CONFIGURE_ARGS=	--with-plugins="${TOTEM_PLUGINS}"
SHEBANG_FILES=	data/totem-bugreport.py
CONFIGURE_ENV+=	APPDATA_VALIDATE="${LOCALBASE}/bin/appdata-validate --nonet"
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.totem.enums.xml \
		org.gnome.totem.gschema.xml \
		org.gnome.totem.plugins.opensubtitles.gschema.xml

OPTIONS_DEFINE=	LIRC

PLIST_SUB+=	PYVER=${PYTHON_VER:S/.//}

OPTIONS_DEFAULT=

# check configure script for allowed_plugins="..." for new plugins
TOTEM_PLUGINS=	apple-trailers autoload-subtitles brasero-disc-recorder chapters \
		dbusservice im-status grilo gromit iplayer media-player-keys \
		nautilus ontop opensubtitles properties recent \
		save-file screensaver screenshot sidebar-test skipto vimeo \
		youtube

# pythonconsole samplepython
# vala sample-vala
# iplayer zeitgeist-dp grilo

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	liblirc_client.so:${PORTSDIR}/comms/lirc
PLIST_SUB+=	LIRC=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} lirc
.else
PLIST_SUB+=	LIRC="@comment "
.endif

.if ${PORT_OPTIONS:MBROWSER_PLUGINS}
CONFIGURE_ARGS+=--enable-browser-plugins \
		--enable-gmp-plugin \
		--enable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS=""

USES+=		webplugin:native
WEBPLUGIN_FILES=	libtotem-cone-plugin.so libtotem-gmp-plugin.so \
			libtotem-mully-plugin.so \
			libtotem-narrowspace-plugin.so
CONFIGURE_ENV+=	BROWSER_PLUGIN_DIR="${WEBPLUGIN_DIR}"

.else
CONFIGURE_ARGS+=--disable-browser-plugins \
		--disable-basic-plugin \
		--disable-gmp-plugin \
		--disable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS="@comment "
.endif

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/cd0
.endif

pre-everything::
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"

post-patch:
	@${CP} -f ${FILESDIR}/pkg-message.in ${PKGMESSAGE}

.include <bsd.port.mk>

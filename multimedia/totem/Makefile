# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$

PORTNAME=	totem
PORTVERSION=	3.18.1
PORTREVISION=	3
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gstreamer-based video player for the GNOME 3 Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:misc/gnome-icon-theme \
		pylint:devel/pylint \
		appstream-glib>=0:devel/appstream-glib \
		itstool:textproc/itstool \
		grilo-plugins2>=0:net/grilo-plugins2
LIB_DEPENDS=	libgdata.so:devel/libgdata \
		libdbus-glib-1.so:devel/dbus-glib \
		libclutter-gst-3.0.so:multimedia/clutter-gst3 \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libpeas-1.0.so:devel/libpeas \
		libtotem-plparser.so:multimedia/totem-pl-parser
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:misc/gnome-icon-theme \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR} \
		gnome-settings-daemon>=2.91.0:sysutils/gnome-settings-daemon \
		gnome-icon-theme-symbolic>=2.91.0:x11-themes/gnome-icon-theme-symbolic \
		grilo-plugins2>=0:net/grilo-plugins2

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libtool \
		pathfix pkgconfig python:2.7 tar:xz
USE_GNOME=	gtk30 intlhack introspection:build libxml2 nautilus3 \
		pygobject3
USE_XORG=	x11 xproto xtst ice sm
USE_GSTREAMER1=	core good bad soup ugly
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lXrandr"
CONFIGURE_ARGS=	--with-plugins="${TOTEM_PLUGINS}"
#CONFIGURE_ENV+=	APPDATA_VALIDATE="${LOCALBASE}/bin/appdata-validate --nonet"
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
LIB_DEPENDS+=	liblirc_client.so:comms/lirc
PLIST_SUB+=	LIRC=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} lirc
.else
PLIST_SUB+=	LIRC="@comment "
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

.include <bsd.port.mk>

# Created by: Hendrik Scholz <hendrik@scholz.net>
# $FreeBSD$

PORTNAME=	totem
PORTVERSION=	3.26.2
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gstreamer-based video player for the GNOME 3 Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		pylint:devel/pylint \
		appstream-glib>=0:devel/appstream-glib \
		itstool:textproc/itstool \
		grilo-plugins>=0:net/grilo-plugins
LIB_DEPENDS=	libgdata.so:devel/libgdata \
		libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gst-3.0.so:multimedia/clutter-gst3 \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libpeas-1.0.so:devel/libpeas \
		libjson-glib-1.0.so:devel/json-glib \
		libgrilo-0.3.so:net/grilo \
		libzeitgeist-2.0.so:sysutils/zeitgeist \
		libtotem-plparser.so:multimedia/totem-pl-parser
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR} \
		gnome-settings-daemon>=2.91.0:sysutils/gnome-settings-daemon \
		gnome-icon-theme-symbolic>=2.91.0:x11-themes/gnome-icon-theme-symbolic \
		grilo-plugins>=0:net/grilo-plugins

PORTSCOUT=	limitw:1,even

USES=		compiler desktop-file-utils gettext gl gnome localbase meson \
		pkgconfig python:3.4+ tar:xz xorg
USE_GNOME=	cairo gtk30 intlhack introspection libxml2 nautilus3 \
		pygobject3
USE_XORG=	x11 xorgproto xtst ice sm
USE_GSTREAMER1=	core good bad soup ugly
INSTALLS_ICONS=	yes
USE_GL=		egl
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.totem.enums.xml \
		org.gnome.totem.gschema.xml \
		org.gnome.totem.plugins.opensubtitles.gschema.xml \
		org.gnome.totem.plugins.pythonconsole.gschema.xml

# There is an upstream issue in meson which makes the build of totem
# fail when using vala, due to badly created targets.
# https://gitlab.gnome.org/GNOME/totem/issues/272
# https://bugzilla.gnome.org/show_bug.cgi?id=786248
# https://github.com/mesonbuild/meson/issues/1994
# Until upstream fixes this, remove vala support from totem.
MESON_ARGS=	-Denable-vala=no
PLIST_SUB+=	VALA="@comment "

.include <bsd.port.options.mk>

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/cd0
.endif

pre-everything::
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	${REINPLACE_CMD} -e '/-Wno-unused-but-set-variable/d' \
		${WRKSRC}/src/plugins/meson.build
.endif

.include <bsd.port.post.mk>

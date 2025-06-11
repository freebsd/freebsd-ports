PORTNAME=	totem
PORTVERSION=	43.1
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gstreamer-based video player for the GNOME 3 Desktop
WWW=		https://apps.gnome.org/Totem/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		pylint:devel/pylint@${PY_FLAVOR} \
		appstream-glib>=0:devel/appstream-glib \
		itstool:textproc/itstool \
		grilo-plugins>=0:net/grilo-plugins
LIB_DEPENDS=	libgdata.so:devel/libgdata \
		libpeas-1.0.so:devel/libpeas1 \
		libjson-glib-1.0.so:devel/json-glib \
		libgrilo-0.3.so:net/grilo \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libhandy-1.so:x11-toolkits/libhandy \
		libportal-gtk3.so:deskutils/libportal-gtk3
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		${PYTHON_PKGNAMEPREFIX}libpeas1>=0:devel/py-libpeas1@${PY_FLAVOR} \
		gnome-settings-daemon>=2.91.0:sysutils/gnome-settings-daemon \
		gnome-icon-theme-symbolic>=2.91.0:x11-themes/gnome-icon-theme-symbolic \
		grilo-plugins>=0:net/grilo-plugins

PORTSCOUT=	limitw:1,even

USES=		compiler desktop-file-utils gettext gl gnome gstreamer localbase meson \
		pkgconfig python tar:xz xorg
USE_GNOME=	cairo gtk30 intlhack introspection libxml2 pygobject3 gnomedesktop3
USE_XORG=	x11 xorgproto xtst ice sm
USE_GSTREAMER=	core good bad soup ugly gtk
USE_GL=		egl
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.totem.enums.xml \
		org.gnome.totem.gschema.xml \
		org.gnome.totem.plugins.opensubtitles.gschema.xml \
		org.gnome.totem.plugins.pythonconsole.gschema.xml

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

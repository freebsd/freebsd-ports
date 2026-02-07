PORTNAME=	totem
PORTVERSION=	43.2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gstreamer-based video player for the GNOME Desktop
WWW=		https://apps.gnome.org/Totem/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	iso-codes>0:misc/iso-codes \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas1 \
		libgrilo-0.3.so:net/grilo \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libhandy-1.so:x11-toolkits/libhandy \
		libportal.so:deskutils/libportal \
		libportal-gtk3.so:deskutils/libportal-gtk3 \
		libepoxy.so:graphics/libepoxy
RUN_DEPENDS=	iso-codes>0:misc/iso-codes \
		gnome-settings-daemon>0:sysutils/gnome-settings-daemon \
		grilo-plugins>=0:net/grilo-plugins

USES=		compiler desktop-file-utils gettext gl gnome gstreamer localbase meson \
		perl5 pkgconfig python tar:xz xorg
USE_GNOME=	cairo gtk30 introspection libxml2 pygobject3 gnomedesktop3
USE_PERL5=	build
USE_XORG=	x11 xorgproto xtst ice sm
USE_GSTREAMER=	core good bad soup ugly gtk
USE_GL=		egl
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_VERSION}

MESON_ARGS=	-Denable-easy-codec-installation=no \
		-Dui-tests=false

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

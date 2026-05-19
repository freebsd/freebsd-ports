PORTNAME=	totem
DISTVERSION=	43.2
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/totem/-/commit/
PATCHFILES=	09d7e8ca6ef4eb59ba086707cf63e80cfb098b80.patch:-p1 \
		eee7d9f7c3fa19409857ea6a8a4ba48c45d1d4cb.patch:-p1 \
		d9ad52972ca817088994554aa1d9e299b8b6c915.patch:-p1 \
		6753353adc90b663eab3add5b488bcd773a58172.patch:-p1 \
		b75e6c2a9e514746159db28412df2db3c939de01.patch:-p1 \
		3ad6d78ff107ca2a57200151043813041eec9883.patch:-p1 \
		e8efc3285d0665b18ac00850fb34bf5b5f19d107.patch:-p1 \
		ca7ce33327b9274594934aff2bd3ecbec417b589.patch:-p1 \
		71b680b72968b19cfa59dd52da780cb6ebbb60de.patch:-p1 \
		19e8bd51ebf2dc31752d05e9274098193db4a3e6.patch:-p1 \
		b95a6231c6b82ba8e3847ecd98c6a524d14215d2.patch:-p1 \
		71f7ee31776fe538ac7d30be05c47b6c01a03671.patch:-p1 \
		acbb0f6998bdae106931bab2a2730bc73df7a97d.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gstreamer-based video player for the GNOME Desktop
WWW=		https://apps.gnome.org/Totem/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	iso-codes>0:misc/iso-codes \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-2.so:devel/libpeas \
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

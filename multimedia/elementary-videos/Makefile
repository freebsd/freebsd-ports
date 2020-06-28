# $FreeBSD$

PORTNAME=	elementary-videos
DISTVERSION=	2.7.1
CATEGORIES=	multimedia

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Elementary OS video player

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libclutter-gst-3.0.so:multimedia/clutter-gst3 \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libgstbase-1.0.so:multimedia/gstreamer1
RUN_DEPENDS=	gstreamer1-plugins-core>=0:multimedia/gstreamer1-plugins-core

USES=		desktop-file-utils gnome meson pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
GH_PROJECT=	videos
USE_GNOME=	cairo gdkpixbuf2 gtk30
GLIB_SCHEMAS=	io.elementary.videos.gschema.xml
INSTALLS_ICONS=	yes
USE_GSTREAMER1=	yes
USE_XORG=	x11

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.mk>

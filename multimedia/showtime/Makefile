PORTNAME=	showtime
DISTVERSION=	48.1
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Video player for the GNOME desktop
WWW=		https://apps.gnome.org/Showtime/

LICENSE=	GPLv3+

BUILD_DEPENDS=	blueprint-compiler>0:devel/blueprint-compiler
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		desktop-file-utils gettext gnome gstreamer meson pkgconfig \
		python tar:xz
USE_GNOME=	glib20 gtk40 libadwaita pygobject3
USE_GSTREAMER=	faad libav ogg opus plugins rust theora vorbis vpx x264
USE_PYTHON=	py3kplist
BINARY_ALIAS=	python3=${PYTHON_CMD}

GLIB_SCHEMAS=	org.gnome.Showtime.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|@PYTHON@|${PYTHON_CMD}|' \
		${WRKSRC}/showtime/showtime.in

.include <bsd.port.mk>

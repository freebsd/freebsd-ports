PORTNAME=	gnome-system-monitor
PORTVERSION=	47.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME system monitor program
WWW=		https://apps.gnome.org/GnomeSystemMonitor/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libgraphene-1.0.so:graphics/graphene
RUN_DEPENDS=	polkit>0:sysutils/polkit

USES=		compiler:c++20-lang gettext gnome localbase meson \
		pkgconfig tar:xz
USE_CXXSTD=	c++20
USE_GNOME=	glib20 glibmm26 gtkmm40 libadwaita librsvg2 libxml2
MESON_ARGS=	-Dsystemd=false

GLIB_SCHEMAS=	org.gnome.gnome-system-monitor.enums.xml \
		org.gnome.gnome-system-monitor.gschema.xml

.include <bsd.port.mk>

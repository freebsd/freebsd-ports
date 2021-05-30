# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gnome-system-monitor
PORTVERSION=	40.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 system monitor program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libhandy-1.so:x11-toolkits/libhandy

PORTSCOUT=	limitw:1,even

USES=		alias compiler:c++11-lang gettext gnome localbase meson \
		pkgconfig tar:xz
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm30 librsvg2 libxml2
USE_GNOME+=	glib20
MESON_ARGS=	-Dsystemd=false

GLIB_SCHEMAS=	org.gnome.gnome-system-monitor.enums.xml \
		org.gnome.gnome-system-monitor.gschema.xml

.include <bsd.port.mk>

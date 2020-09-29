# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-system-monitor
PORTVERSION=	3.38.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 system monitor program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop

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

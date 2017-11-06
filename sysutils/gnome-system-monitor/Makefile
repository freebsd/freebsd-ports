# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-system-monitor
PORTVERSION=	3.16.0
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 system monitor program

BUILD_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme

PORTSCOUT=	limitw:1,even

USES=		alias compiler:c++11-lang gettext gmake localbase pathfix pkgconfig tar:xz
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm30 intlhack librsvg2 libwnck3
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gnome-system-monitor.enums.xml \
		org.gnome.gnome-system-monitor.gschema.xml

.include <bsd.port.mk>

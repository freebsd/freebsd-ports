# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	mate-system-monitor
PORTVERSION=	1.24.2
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE system monitor program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libdbus-glib-1.so:devel/dbus-glib

PORTSCOUT=	limitw:1,even

USES=		alias compiler:c++11-lib gettext gmake gnome localbase mate \
		pathfix pkgconfig tar:xz
USE_MATE=	icontheme
USE_GNOME=	gtkmm30 intlhack librsvg2 libwnck3 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-systemd
CONFIGURE_ENV=	LIBS="-lutil" DATADIRNAME="share"

GLIB_SCHEMAS=	org.mate.system-monitor.enums.xml \
		org.mate.system-monitor.gschema.xml

.include <bsd.port.mk>

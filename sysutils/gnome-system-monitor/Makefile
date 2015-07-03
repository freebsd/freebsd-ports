# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-system-monitor/Makefile 19972 2014-10-16 09:40:45Z gusi $

PORTNAME=	gnome-system-monitor
PORTVERSION=	3.14.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 system monitor program

BUILD_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme

USES=		alias gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtkmm30 intlhack librsvg2 libwnck3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gnome-system-monitor.enums.xml \
		org.gnome.gnome-system-monitor.gschema.xml

.include <bsd.port.mk>

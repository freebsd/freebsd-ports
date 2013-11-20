# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-system-monitor3/Makefile 18579 2013-06-23 08:34:44Z kwm $

PORTNAME=	gnome-system-monitor
PORTVERSION=	3.6.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 system monitor program

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix gtkmm30 intlhack librsvg2 libwnck3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.gnome-system-monitor.enums.xml \
		org.gnome.gnome-system-monitor.gschema.xml

.include <bsd.port.mk>

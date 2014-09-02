# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-system-monitor/Makefile,v 1.147 2012/10/02 15:10:10 kwm Exp $

PORTNAME=	gnome-system-monitor
PORTVERSION=	2.28.2
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 system monitor program

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

CONFLICTS=	gnome-system-monitor-3.[0-9]*

USES=		gettext gmake pkgconfig tar:bzip2
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix intlhack libwnck gnomevfs2 gnomedocutils librsvg2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lgmodule-2.0 -lutil

GCONF_SCHEMAS=	gnome-system-monitor.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|<glib/gtypes.h>|<glib.h>|g' \
		-e 's|<glib/gmacros.h>|<glib.h>|g' \
		-e 's|<glib/gstring.h>|<glib.h>|g' \
		${WRKSRC}/src/*.[ch] ${WRKSRC}/src/*.cpp

.include <bsd.port.mk>

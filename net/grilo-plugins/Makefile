# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/net/grilo-plugins/Makefile 19593 2014-04-28 11:41:58Z gusi $

PORTNAME=	grilo-plugins
PORTVERSION=	0.2.12
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for net/grilo

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgrilo-0.2.so:${PORTSDIR}/net/grilo

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomehier intlhack libxml2 
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/grilo-0.2/
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_SUB=			yes
OPTIONS_DEFINE=                 TRACKER
OPTIONS_DEFAULT=                TRACKER
TRACKER_CONFIGURE_ENABLE=	migration
TRACKER_LIB_DEPENDS=		libtracker-sparql-1.0.so:${PORTSDIR}/sysutils/tracker
TRACKER_DESC=			Tracker support for grilo (used by gnome-music and possibly others)

.include <bsd.port.mk>

# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/totem-pl-parser/Makefile,v 1.45 2011/02/21 19:10:03 kwm Exp $

PORTNAME=	totem-pl-parser
PORTVERSION=	2.32.3
PORTREVISION=	2
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gmime-2.4:${PORTSDIR}/mail/gmime24 \
		soup-gnome-2.4:${PORTSDIR}/devel/libsoup-gnome
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		pathfix gettext pkgconfig
USE_GNOME=	gnomeprefix glib20 libxml2 intlhack ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	QUVI
QUVI_DESC=	Enable flash media stream URL support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQUVI}
LIB_DEPENDS+=	quvi:${PORTSDIR}/multimedia/libquvi
CONFIGURE_ARGS+=--enable-enable-quvi
.else
CONFIGURE_ARGS+=--enable-enable-quvi=no
.endif

.include <bsd.port.mk>

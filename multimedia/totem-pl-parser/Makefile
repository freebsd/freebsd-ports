# New ports collection makefile for:	totem-pl-parser
# Date created:		2007-12-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/totem-pl-parser/Makefile,v 1.45 2011/02/21 19:10:03 kwm Exp $
#

PORTNAME=	totem-pl-parser
PORTVERSION=	2.32.3
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gmime-2.4.6:${PORTSDIR}/mail/gmime24 \
		soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix glib20 libxml2 intlhack ltverhack
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	QUVI "Enable flash media stream URL support"  off

.include <bsd.port.options.mk>

.if defined(WITH_QUVI)
LIB_DEPENDS+=	quvi.7:${PORTSDIR}/multimedia/libquvi
CONFIGURE_ARGS+=--enable-enable-quvi
.else
CONFIGURE_ARGS+=--enable-enable-quvi=no
.endif

.include <bsd.port.mk>


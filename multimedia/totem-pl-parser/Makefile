# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/totem-pl-parser/Makefile,v 1.45 2011/02/21 19:10:03 kwm Exp $

PORTNAME=	totem-pl-parser
PORTVERSION=	2.32.3
PORTREVISION=	4
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	libgmime-2.4.so:${PORTSDIR}/mail/gmime24 \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

USES=		pathfix gettext pkgconfig gmake libtool tar:bzip2
USE_GNOME=	gnomeprefix glib20 libxml2 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	QUVI
QUVI_DESC=	Enable flash media stream URL support

QUVI_LIB_DEPENDS=	libquvi.so:${PORTSDIR}/multimedia/libquvi
QUVI_CONFIGURE_ON=	--enable-enable-quvi
QUVI_CONFIGURE_OFF	=--enable-enable-quvi=no

.include <bsd.port.mk>

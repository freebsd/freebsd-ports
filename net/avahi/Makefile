# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/avahi/Makefile,v 1.30 2011/03/13 17:23:19 kwm Exp $

PORTNAME=	avahi
PORTVERSION=	0.6.31
PORTREVISION?=	1
CATEGORIES?=	net dns

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"meta-port" for the Avahi service discovery suite

RUN_DEPENDS=	avahi-app>=0.6.31:net/avahi-app

USES=		metaport

OPTIONS_DEFINE=	AUTOIPD GTK MONO QT4 PYTHON
OPTIONS_DEFAULT=AUTOIPD GTK
AUTOIPD_DESC=	IPv4LL network address configuration daemon
GTK_DESC=	Gtk+ tools and bindings
LIBDNS_DESC=	Apple's mDNSResponder compatibility library

AUTOIPD_RUN_DEPENDS=	avahi-autoipd:net/avahi-autoipd
GTK_RUN_DEPENDS=	avahi-discover-standalone:net/avahi-gtk
#LIBDNS_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/avahi-compat-libdns_sd.pc:net/avahi-libdns
MONO_RUN_DEPENDS=	${LOCALBASE}/lib/mono/avahi-sharp/avahi-sharp.dll:net/avahi-sharp
QT4_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/avahi-qt4.pc:net/avahi-qt4
PYTHON_RUN_DEPENDS=	avahi-bookmarks:net/py-avahi

.include <bsd.port.mk>

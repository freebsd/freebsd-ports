# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/avahi/Makefile,v 1.30 2011/03/13 17:23:19 kwm Exp $

PORTNAME=	avahi
PORTVERSION=	0.6.31
PORTREVISION?=	0
CATEGORIES?=	net dns
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for the Avahi service discovery suite

RUN_DEPENDS=	avahi-resolve:${PORTSDIR}/net/avahi-app \
		avahi-app>=0.6.31:${PORTSDIR}/net/avahi-app

OPTIONS_DEFINE=	AUTOIPD GTK LIBDNS MONO QT4 PYTHON
OPTIONS_DEFAULT=AUTOIPD GTK LIBDNS
AUTOIPD_DESC=	IPv4LL network address configuration daemon
GTK_DESC=	Gtk+ tools and bindings
LIBDNS_DESC=	Apple's mDNSResponder compatibility library

NO_BUILD=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAUTOIPD}
RUN_DEPENDS+=	avahi-autoipd:${PORTSDIR}/net/avahi-autoipd
.endif

.if ${PORT_OPTIONS:MGTK}
RUN_DEPENDS+=	avahi-discover-standalone:${PORTSDIR}/net/avahi-gtk
.endif

.if ${PORT_OPTIONS:MLIBDNS}
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/avahi-compat-libdns_sd.pc:${PORTSDIR}/net/avahi-libdns
.endif

.if ${PORT_OPTIONS:MMONO}
RUN_DEPENDS+=	${LOCALBASE}/lib/mono/avahi-sharp/avahi-sharp.dll:${PORTSDIR}/net/avahi-sharp
.endif

.if ${PORT_OPTIONS:MQT4}
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/avahi-qt4.pc:${PORTSDIR}/net/avahi-qt4
.endif

.if ${PORT_OPTIONS:MPYTHON}
RUN_DEPENDS+=	avahi-bookmarks:${PORTSDIR}/net/py-avahi
.endif

do-install:

.include <bsd.port.mk>

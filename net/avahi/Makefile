# New ports collection makefile for:	avahi
# Date created:		18 November 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/avahi/Makefile,v 1.26 2007/09/09 22:45:27 mezz Exp $
#

PORTNAME=	avahi
PORTVERSION=	0.6.27
PORTREVISION?=	0
CATEGORIES?=	net dns
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for the Avahi service discovery suite

RUN_DEPENDS=	avahi-resolve:${PORTSDIR}/net/avahi-app \
		avahi-app>=0.6.20_2:${PORTSDIR}/net/avahi-app

OPTIONS=	AUTOIPD "IPv4LL network address configuration daemon" off \
		GTK "Gtk+ tools and bindings" off \
		LIBDNS "Apple's mDNSResponder compatibility library" off \
		MONO "Mono bindings" off \
		QT3 "Qt 3 bindings" off \
		QT4 "Qt 4 bindings" off \
		PYTHON "Python bindings and tools" off

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_AUTOIPD)
RUN_DEPENDS+=	avahi-autoipd:${PORTSDIR}/net/avahi-autoipd
.endif

.if defined(WITH_GTK)
RUN_DEPENDS+=	avahi-discover-standalone:${PORTSDIR}/net/avahi-gtk
.endif

.if defined(WITH_LIBDNS)
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/avahi-compat-libdns_sd.pc:${PORTSDIR}/net/avahi-libdns
.endif

.if defined(WITH_MONO)
RUN_DEPENDS+=	${LOCALBASE}/lib/mono/avahi-sharp/avahi-sharp.dll:${PORTSDIR}/net/avahi-sharp
.endif

.if defined(WITH_QT3)
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/avahi-qt3.pc:${PORTSDIR}/net/avahi-qt3
.endif

.if defined(WITH_QT4)
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/avahi-qt4.pc:${PORTSDIR}/net/avahi-qt4
.endif

.if defined(WITH_PYTHON)
RUN_DEPENDS+=	avahi-bookmarks:${PORTSDIR}/net/py-avahi
.endif

do-install:

.include <bsd.port.post.mk>

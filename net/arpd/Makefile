# Ports collection makefile for:  arpd
# Date created:                   16/04/2002
# Whom:                           Dominic Marks <dominic_marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	arpd
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	yb@sainte-barbe.org
COMMENT=	A daemon to service arp replies

BUILD_DEPENDS=	${LOCALBASE}/include/dnet.h:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/include/event.h:${PORTSDIR}/devel/libevent
RUN_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

MAN8=		arpd.8
PLIST_FILES=	sbin/arpd

.include <bsd.port.mk>

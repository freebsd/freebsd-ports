# Ports collection makefile for:  arpd
# Date created:                   16/04/2002
# Whom:                           Dominic Marks <dominic_marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	arpd
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	http://www.citi.umich.edu/u/provos/honeyd/

MAINTAINER=	dominc_marks@btinternet.com

BUILD_DEPENDS=	${LOCALBASE}/include/dnet.h:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/include/event.h:${PORTSDIR}/devel/libevent
RUN_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet \
		${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

CONFIGURE_ARGS=	--with-libdnet=${LOCALBASE} \
		--with-libevent=${LOCALBASE} \
		--with-pcap
GNU_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

MAN8=	arpd.8

.include <bsd.port.mk>

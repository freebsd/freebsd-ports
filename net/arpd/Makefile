# Ports collection makefile for:  arpd
# Date created:                   16/04/2002
# Whom:                           Dominic Marks <dominic_marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	arpd
PORTVERSION=	0.2
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A daemon to service arp replies

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent \
		dnet.1:${PORTSDIR}/net/libdnet

BROKEN=		does not build

GNU_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

MAN8=		arpd.8
PLIST_FILES=	sbin/arpd

.include <bsd.port.mk>

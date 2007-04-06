# Ports collection makefile for:  arpd
# Date created:                   16/04/2002
# Whom:                           Dominic Marks <dominic_marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	arpd
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	yb@bashibuzuk.net
COMMENT=	A daemon to service arp replies

LIB_DEPENDS=	event-1.3b:${PORTSDIR}/devel/libevent \
		dnet.1:${PORTSDIR}/net/libdnet

GNU_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

MAN8=		arpd.8
PLIST_FILES=	sbin/arpd

.include <bsd.port.mk>

# Ports collection makefile for:  nemesis
# Date created:			  Fri July 07, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nemesis
PORTVERSION=	1.2
CATEGORIES=	net security
MASTER_SITES=	http://www.packetninja.net/nemesis/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CCOPTS="${CFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \

MAN1=		nemesis-arp.1 nemesis-dns.1 nemesis-icmp.1 nemesis-igmp.1 \
		nemesis-ospf.1 nemesis-rip.1 nemesis-tcp.1 nemesis-udp.1

.include <bsd.port.mk>

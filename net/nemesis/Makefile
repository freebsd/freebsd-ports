# ex:ts=8
# Ports collection makefile for:  nemesis
# Date created:			  Fri July 07, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nemesis
PORTVERSION=	1.1
CATEGORIES=	net security
MASTER_SITES=	http://celerity.bartoli.org/nemesis/  \
		http://www.packetfactory.net/Projects/nemesis/  \
		http://www.nol.net/~halogen/

MAINTAINER=     obrien@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
MAN1=		nemesis-arp.1 nemesis-dns.1 nemesis-icmp.1 nemesis-igmp.1
MAN1+=		nemesis-ospf.1 nemesis-rip.1 nemesis-tcp.1 nemesis-udp.1

.include <bsd.port.mk>

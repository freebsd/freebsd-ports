# Ports collection makefile for:  nemesis
# Date created:			  Fri July 07, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nemesis
PORTVERSION=	1.4.b3
PORTEPOCH=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/projects/nemesis/
DISTNAME=	nemesis-1.4beta3

MAINTAINER=	molter@tin.it
COMMENT=	Command-line UNIX network packet creation and injection suite

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CCOPTS="${CFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \

MAN1=		nemesis-arp.1 nemesis-dns.1 nemesis-ethernet.1 nemesis-icmp.1 \
		nemesis-igmp.1 nemesis-ip.1 nemesis-ospf.1 nemesis-rip.1 \
		nemesis-tcp.1 nemesis-udp.1 nemesis.1

.include <bsd.port.mk>

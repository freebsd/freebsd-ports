# Ports collection makefile for:  nemesis
# Date created:			  Fri July 07, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nemesis
PORTVERSION=	1.4
PORTEPOCH=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	molter@tin.it
COMMENT=	Command-line network packet creation and injection suite

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnet-includes="${LOCALBASE}/include" \
		--with-libnet-libraries="${LOCALBASE}/lib"

MAN1=		nemesis-arp.1 nemesis-dns.1 nemesis-ethernet.1 nemesis-icmp.1 \
		nemesis-igmp.1 nemesis-ip.1 nemesis-ospf.1 nemesis-rip.1 \
		nemesis-tcp.1 nemesis-udp.1 nemesis.1
PLIST_FILES=	bin/nemesis

.include <bsd.port.mk>

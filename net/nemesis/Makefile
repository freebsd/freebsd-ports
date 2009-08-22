# Ports collection makefile for:  nemesis
# Date created:			  Fri July 07, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nemesis
PORTVERSION=	1.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	molter@tin.it
COMMENT=	Command-line network packet creation and injection suite

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnet-includes="${LOCALBASE}/include" \
		--with-libnet-libraries="${LOCALBASE}/lib"

MAN1=		nemesis-arp.1 nemesis-dns.1 nemesis-ethernet.1 nemesis-icmp.1 \
		nemesis-igmp.1 nemesis-ip.1 nemesis-ospf.1 nemesis-rip.1 \
		nemesis-tcp.1 nemesis-udp.1 nemesis.1
PLIST_FILES=	bin/nemesis

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-patch:
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>

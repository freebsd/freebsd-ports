# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	nemesis
PORTVERSION=	1.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net security
MASTER_SITES=	SF

MAINTAINER=	molter@tin.it
COMMENT=	Command-line network packet creation and injection suite

DEPRECATED=	Depends on expired net/libnet10
EXPIRATION_DATE=	2014-09-30

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnet-includes="${LOCALBASE}/include" \
		--with-libnet-libraries="${LOCALBASE}/lib"

PLIST_FILES=	bin/nemesis \
		man/man1/nemesis-arp.1.gz \
		man/man1/nemesis-dns.1.gz \
		man/man1/nemesis-ethernet.1.gz \
		man/man1/nemesis-icmp.1.gz \
		man/man1/nemesis-igmp.1.gz \
		man/man1/nemesis-ip.1.gz \
		man/man1/nemesis-ospf.1.gz \
		man/man1/nemesis-rip.1.gz \
		man/man1/nemesis-tcp.1.gz \
		man/man1/nemesis-udp.1.gz \
		man/man1/nemesis.1.gz

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-patch:
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>

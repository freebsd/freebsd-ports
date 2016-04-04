# Created by: ijliao
# $FreeBSD$

PORTNAME=	arp-sk
PORTVERSION=	0.0.16
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://sid.rstack.org/arp-sk/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool designed to manipulate ARP tables of all kinds of equipment

LIB_DEPENDS=	libnet.so:net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnet=${LOCALBASE}

PLIST_FILES=	sbin/arp-sk man/man1/arp-sk.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/arp-sk ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/arp-sk.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

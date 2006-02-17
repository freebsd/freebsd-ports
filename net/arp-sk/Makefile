# ex:ts=8
# Ports collection makefile for:	arp-sk
# Date Created:			Apr 14, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	arp-sk
PORTVERSION=	0.0.16
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://sid.rstack.org/arp-sk/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool designed to manipulate ARP tables of all kinds of equipment

BUILD_DEPENDS=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes

MAN1=	arp-sk.1
PLIST_FILES=	sbin/arp-sk

post-patch:
	@${REINPLACE_CMD} -e "s, -pedantic -g,," ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/arp-sk ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/arp-sk.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

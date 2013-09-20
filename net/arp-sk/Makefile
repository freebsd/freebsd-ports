# Created by: ijliao
# $FreeBSD$

PORTNAME=	arp-sk
PORTVERSION=	0.0.16
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://sid.rstack.org/arp-sk/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool designed to manipulate ARP tables of all kinds of equipment

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CFLAGS+=	`${LIBNET_CONFIG} --cflags`

MAN1=	arp-sk.1
PLIST_FILES=	sbin/arp-sk

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -Ee \
		's| -pedantic -g||; \
		 s|test -f \$${prefix}/include/libnet\.h|${TRUE}|; \
		 s|\$$NETINC/libnet\.h|libnet.h|; \
		 s|(NETINC=).*|\1"`${LIBNET_CONFIG} --defines` `${LIBNET_CONFIG} --cflags`"|; \
		 s|(NETLIB=).*|\1"`${LIBNET_CONFIG} --libs`"|' \
		 ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/arp-sk ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/arp-sk.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

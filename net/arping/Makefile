# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	arping
PORTVERSION=	2.13
CATEGORIES=	net
MASTER_SITES=	http://www.habets.pp.se/synscan/files/

MAINTAINER=	gavin@FreeBSD.org
COMMENT=	ARP level "ping" utility

LIB_DEPENDS=	net:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="`${LIBNET_CONFIG} --libs` -lpcap"
CFLAGS+=	`${LIBNET_CONFIG} --defines`
CPPFLAGS+=	-I${LOCALBASE}/include `${LIBNET_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

PLIST_FILES=	sbin/arping man/man8/arping.8.gz

.include <bsd.port.mk>

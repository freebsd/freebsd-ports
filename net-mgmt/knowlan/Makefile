# Ports collection makefile for:	knowlan
# Date Created:			2003-10-27
# Whom:				Omer Faruk Sen <ofsen@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	knowlan
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.enderunix.org/knowlan/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ARP-based LAN IP and MAC Address Extractor

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX="${PREFIX}" LOCALBASE="${LOCALBASE}"
CFLAGS+=	`${LIBNET_CONFIG} --cflags`

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-patch:
	@${REINPLACE_CMD} -e \
		'95d; 102d; 116,117d; \
		 s|libnet-config|${LIBNET_CONFIG}|; \
		 s|$${LOCALBASE}/lib/libnet.a|`${LIBNET_CONFIG} --libs`|; \
		 s|gcc|${CC}|' \
		 ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/knowlan ${PREFIX}/sbin

.include <bsd.port.mk>

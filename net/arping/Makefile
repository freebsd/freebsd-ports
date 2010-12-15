# New ports collection makefile for:	arping
# Date Created:				1 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	arping
PORTVERSION=	2.09
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.habets.pp.se/synscan/files/

MAINTAINER=	gavin@FreeBSD.org
COMMENT=	ARP level "ping" utility

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS+="`${LIBNET_CONFIG} --defines`" \
		CPPFLAGS="-I${LOCALBASE}/include `${LIBNET_CONFIG} --cflags`" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="`${LIBNET_CONFIG} --libs` -lpcap"

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

MAN8=		arping.8
PLIST_FILES=	sbin/arping

.include <bsd.port.mk>

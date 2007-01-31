# New ports collection makefile for:	cdpd
# Date created:				26 Sep 2001
# Whom:					Alexandre Snarskii <snar@paranoia.ru>
#
# $FreeBSD$

PORTNAME=	cdpd
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CDPdaemon - sends Cisco Discovery Protocol announces over ethernet

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

GNU_CONFIGURE=	yes
CFLAGS+=	`${LIBNET_CONFIG} --cflags`

MAN8=	cdpd.8

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-patch:
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG:T}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>

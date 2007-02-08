# New ports collection makefile for:	cdpd
# Date created:				26 Sep 2001
# Whom:					Alexandre Snarskii <snar@paranoia.ru>
#
# $FreeBSD$

PORTNAME=	cdpd
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A daemon to send Cisco Discovery Protocol announces over ethernet

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

GNU_CONFIGURE=	yes
CFLAGS+=	`${LIBNET_CONFIG} --cflags`

USE_RC_SUBR=	cdpd
PLIST_FILES=	sbin/cdpd

MAN8=	cdpd.8

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-patch:
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG:T}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdpd ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/cdpd.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>

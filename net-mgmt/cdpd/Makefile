# New ports collection makefile for:	cdpd
# Date created:				26 Sep 2001
# Whom:					Alexandre Snarskii <snar@paranoia.ru>
#
# $FreeBSD$

PORTNAME=	cdpd
PORTVERSION=	1.0.2
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	snar@paranoia.ru
COMMENT=	CDPdaemon - sends Cisco Discovery Protocol announces over ethernet

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes

MAN8=	cdpd.8

.include <bsd.port.mk>

# New ports collection makefile for:	ipfm
# Date Created:				4 Mar 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	ipfm
PORTVERSION=	0.11.4
CATEGORIES=	net
MASTER_SITES=	http://robert.cheramy.net/ipfm/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	roman@xpert.com

GNU_CONFIGURE=	yes

MAN5=		ipfm.conf.5
MAN8=		ipfm.8

post-install:
	@strip ${PREFIX}/sbin/ipfm

.include <bsd.port.mk>

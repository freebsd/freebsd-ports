# New ports collection makefile for:	ipfm
# Date Created:				4 Mar 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	ipfm
PORTVERSION=	0.11.5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://robert.cheramy.net/ipfm/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@oven.org
COMMENT=	A bandwidth analysis tool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var

MAN5=		ipfm.conf.5
MAN8=		ipfm.8

post-install:
	@${STRIP_CMD} ${PREFIX}/sbin/ipfm

.include <bsd.port.mk>

# New ports collection makefile for:	arpalert
# Date created:				11 May 2006
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arpalert
PORTVERSION=	1.1.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.arpalert.org/src/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	ARP traffic monitoring

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --mandir=${PREFIX}/man
ALL_TARGET=	${PORTNAME}
USE_GETOPT_LONG=yes

MAN8=		arpalert.8

.include <bsd.port.mk>

# New ports collection makefile for:	slsc
# Date created:			6 January 2000
# Whom:				Jonathan McDowell <noodles@earth.li>
#
# $FreeBSD$
#

PORTNAME=	slsc
PORTVERSION=	0.2.3
CATEGORIES=	math
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slsc/
DISTNAME=	${PORTNAME}

MAINTAINER=	noodles@earth.li

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes

post-install:
	strip ${PREFIX}/bin/slsc ${PREFIX}/share/slsc/vprint

.include <bsd.port.mk>

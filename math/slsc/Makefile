# New ports collection makefile for:	slsc
# Version required:		0.2.3
# Date created:			6 January 2000
# Whom:				Jonathan McDowell <noodles@earth.li>
#
# $FreeBSD$
#

DISTNAME=	slsc
PKGNAME=	slsc-0.2.3
CATEGORIES=	math
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slsc/

MAINTAINER=	noodles@earth.li

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes

post-install:
	strip ${PREFIX}/bin/slsc ${PREFIX}/share/slsc/vprint

.include <bsd.port.mk>

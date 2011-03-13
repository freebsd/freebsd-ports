# New ports collection makefile for:	growspd
# Date created:				16 July 2003
# Whom:					Peter Kolmisoppi <growspd@brokep.com>
#
# $FreeBSD$
#

PORTNAME=	growspd
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://growspd.brokep.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick utility to check files growth rate

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN1=		growspd.1
PLIST_FILES=	bin/growspd

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>

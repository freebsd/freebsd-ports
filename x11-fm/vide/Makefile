# New ports collection makefile for:	vide
# Date created:				May 17 2000
# Whom:					careilly
#
# $FreeBSD$
#

PORTNAME=	vide
PORTVERSION=	0.2.6
CATEGORIES=	x11-fm
MASTER_SITES=	http://vide.sourceforge.net/

MAINTAINER=	careilly@thecia.ie

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

CFLAGS+=	-DHAVE_SYS_PARAM_H
MANCOMPRESSED=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>

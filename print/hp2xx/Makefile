# New ports collection makefile for:    hp2xx
# Date created:         17 Jan 1999
# Whom:                 Lars Koeller
#
# $FreeBSD$
#

PORTNAME=	hp2xx
PORTVERSION=	3.20
CATEGORIES=	print x11
MASTER_SITES=	ftp://ftp.rz.uni-duesseldorf.de/pub/graphics/ \
		ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/
DISTNAME=	hp2xx-3.20-png

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${DISTNAME}/sources
USE_XLIB=	yes
MAKEFILE=	makefile
MAN1=		hp2xx.1

post-install:
.for info in hp2xx.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:    hp2xx
# Date created:         17 Jan 1999
# Whom:                 Lars Koeller
#
# $FreeBSD$
#

PORTNAME=	hp2xx
PORTVERSION=	3.4.2
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${DISTNAME}/sources
USE_XLIB=	yes

MAN1=		hp2xx.1

post-install:
.for info in hp2xx.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>

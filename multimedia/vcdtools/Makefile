# ex:ts=8
# New ports collection makefile for:	vcdtools
# Date created:	 	Mar 9, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vcdtools
PORTVERSION=	0.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.mpegnews.com/files/video/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
.for f in mkvcdfs vcdmplex
	@${CP} ${WRKSRC}/$f ${PREFIX}/bin
.endfor

.include <bsd.port.mk>

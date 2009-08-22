# New ports collection makefile for:	ghmm
# Date created:		2006-07-26
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ghmm
PORTVERSION=	0.7.0b
CATEGORIES=	science math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	General Hidden Markov Model Library in C

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-0.7.0

post-patch:
	@${REINPLACE_CMD} 's|tests doc VisualC|tests VisualC|' ${WRKSRC}/configure

.include <bsd.port.mk>

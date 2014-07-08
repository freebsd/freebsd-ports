# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghmm
PORTVERSION=	0.7.0b
PORTREVISION=	1
CATEGORIES=	science math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	General Hidden Markov Model Library in C

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-0.7.0

post-patch:
	@${REINPLACE_CMD} 's|tests doc VisualC|tests VisualC|' ${WRKSRC}/configure

.include <bsd.port.mk>

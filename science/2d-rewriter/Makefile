# Created by: Igor Serikov <iserikov@acm.org>
# $FreeBSD$

PORTNAME=	2d-rewriter
PORTVERSION=	1.4
CATEGORIES=	science
MASTER_SITES=	http://www.crowdeduniverse.org/distfiles/

MAINTAINER=	iserikov@acm.org
COMMENT=	Cellular automata simulator

MAN1=		2d-rewriter.1
MANCOMPRESSED=	yes
USES=		imake
USE_XORG=	x11 xext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>

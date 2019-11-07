# Created by: Igor Serikov <iserikov@acm.org>
# $FreeBSD$

PORTNAME=	2d-rewriter
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	science
#MASTER_SITES=	http://www.crowdeduniverse.org/distfiles/

MAINTAINER=	iserikov@acm.org
COMMENT=	Cellular automata simulator

USES=		imake xorg
USE_XORG=	x11 xext
USE_GITHUB=	yes
GH_ACCOUNT=	iserikov

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>

# Created by: Igor Serikov <iserikov@acm.org>
# $FreeBSD$

PORTNAME=	2d-rewriter
PORTVERSION=	1.6
CATEGORIES=	science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cellular automata simulator

USES=		imake xorg
USE_XORG=	x11 xext
USE_GITHUB=	yes
GH_ACCOUNT=	iserikov

OPTIONS_DEFINE=	EXAMPLES

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

PORTNAME=	2d-rewriter
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cellular automata simulator
WWW=		https://github.com/iserikov/2d-rewriter

USES=		imake xorg
USE_XORG=	x11 xext
USE_GITHUB=	yes
GH_ACCOUNT=	iserikov

OPTIONS_DEFINE=	EXAMPLES

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

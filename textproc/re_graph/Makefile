# Created by: ijliao
# $FreeBSD$

PORTNAME=	re_graph
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.oualline.com/sw/re/
DISTNAME=	${PORTNAME:S/_/-/}_${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Regular Expression Graphing Program

RUN_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-GD-Arrow>=0:${PORTSDIR}/graphics/p5-GD-Arrow

USES=		perl5
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PERL5=	run

PLIST_FILES=	bin/re_graph

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/re_graph.pl ${STAGEDIR}${PREFIX}/bin/re_graph
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/re_graph.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tut* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

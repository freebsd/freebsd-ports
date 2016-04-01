# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	easylatex
PORTVERSION=	0.080
CATEGORIES=	print textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Perl script which transforms "pseudo-LaTeX" into proper LaTeX

RUN_DEPENDS=	p5-Getopt-Declare>=0:devel/p5-Getopt-Declare

NO_BUILD=	yes
USES=		perl5 shebangfix

SHEBANG_FILES=	${PORTNAME}.pl

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/easylatex,${DATADIR},' \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo.txt ${WRKSRC}/demo-no-graph.txt \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

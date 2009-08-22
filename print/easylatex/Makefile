# New ports collection makefile for:	easylatex
# Date created:		2006-02-15
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	easylatex
PORTVERSION=	0.062
PORTREVISION=	2
CATEGORIES=	print textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Perl script which transforms "pseudo-LaTeX" into proper LaTeX

RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
PERL_RUN_DEPENDS=	Getopt-Declare:${PORTSDIR}/devel/p5-Getopt-Declare

NO_BUILD=	yes
USE_PERL5=	yes

FIND_DIRS=	.
PORTDOCS=	TUTORIAL demo.txt demo-no-graph.txt

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/easylatex,${DATADIR},' \
		${WRKSRC}/${PORTNAME}.pl

do-install:
# script/data
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/${PORTNAME} && ${FIND} ${FIND_DIRS} -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC}/${PORTNAME} && ${FIND} ${FIND_DIRS} -type f -name "*.pl" -exec ${INSTALL_SCRIPT} {} ${DATADIR}/{} \;
	cd ${WRKSRC}/${PORTNAME} && ${FIND} ${FIND_DIRS} -type f -name "*.txt" -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
# docs
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>

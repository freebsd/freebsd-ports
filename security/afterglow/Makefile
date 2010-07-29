# New ports collection makefile for:	afterglow
# Date created:				1 Aug 2007
# Whom:					pauls
#
# $FreeBSD$
#

PORTNAME=	afterglow
PORTVERSION=	1.6.0
CATEGORIES=	security graphics
MASTER_SITES=	SF/${PORTNAME}/AfterGlow%201.x/${PORTVERSION}

MAINTAINER=	pauls@utdallas.edu
COMMENT=	A collection of graph-generating scripts

RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

CHARTS_SCRIPTS=	bar.pl bar2.pl boxplot.pl bubble.pl scatter.pl trendline.pl trendline2.pl
GRAPH_SCRIPTS=	afterglow.pl afterglow-lgl.pl
LOGANALYSIS_SCRIPTS=	 anonymize.pl capper.pl merge_logs.pl overview.sh random_logs.pl
PARSERS=	argus2csv.pl ipfw2csv.pl pf2csv.pl sendmail_parser.pl snortalert2csv.pl tcpdump2csv.pl

do-install:
	${MKDIR} ${DATADIR}/data
	${MKDIR} ${DATADIR}/charts
	${MKDIR} ${DATADIR}/graph/Text
	${MKDIR} ${DATADIR}/loganalysis
	${MKDIR} ${DATADIR}/parsers
	(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${DATADIR}/data "! -name generate.pl")
	(cd ${WRKSRC}/src/perl/charts/ && ${COPYTREE_SHARE} \* ${DATADIR}/charts "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/graph/ && ${COPYTREE_SHARE} \* ${DATADIR}/graph "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/loganalysis/ && ${COPYTREE_SHARE} \* ${DATADIR}/loganalysis "! ( -name *\.pl -or -name *\.sh )")
	(cd ${WRKSRC}/src/perl/parsers/ && ${COPYTREE_SHARE} \* ${DATADIR}/parsers "! -name *\.pl")
	${INSTALL_SCRIPT} ${WRKSRC}/data/generate.pl ${DATADIR}/data/
.for f in ${CHARTS_SCRIPTS}
		${INSTALL_SCRIPT} ${WRKSRC}/src/perl/charts/${f} ${DATADIR}/charts/${f}
.endfor
.for f in ${GRAPH_SCRIPTS}
		${INSTALL_SCRIPT} ${WRKSRC}/src/perl/graph/${f} ${DATADIR}/graph/${f}
.endfor
.for f in ${LOGANALYSIS_SCRIPTS}
		${INSTALL_SCRIPT} ${WRKSRC}/src/perl/loganalysis/${f} ${DATADIR}/loganalysis/${f}
.endfor
.for f in ${PARSERS}
		${INSTALL_SCRIPT} ${WRKSRC}/src/perl/parsers/${f} ${DATADIR}/parsers/${f}
.endfor

.include <bsd.port.mk>

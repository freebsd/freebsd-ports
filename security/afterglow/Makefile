# New ports collection makefile for:	afterglow
# Date created:				1 Aug 2007
# Whom:					pauls
#
# $FreeBSD$
#

PORTNAME=	afterglow
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	security graphics
MASTER_SITES=	SF/${PORTNAME}/AfterGlow%201.x/${PORTVERSION}

MAINTAINER=	pauls@utdallas.edu
COMMENT=	A collection of graph-generating scripts

RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

DB_SCRIPTS=	attackchains.pl deltacalc2.pl deltacalc.pl iptolong.pl \
		snortalert.pl snortdirection.pl snortservice.pl subquery.pl \
		tcpdump2sql.pl
GRAPH_SCRIPTS=	afterglow-lgl.pl afterglow-lgl2.pl afterglow-walrus.pl afterglow.pl
PARSERS=	pf2csv.pl sendmail_parser.pl tcpdump2csv.pl

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/data
	${MKDIR} ${DATADIR}/database
	${MKDIR} ${DATADIR}/graph
	${MKDIR} ${DATADIR}/parsers
	(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${DATADIR}/data "! -name generate.pl")
	(cd ${WRKSRC}/src/perl/database/ && ${COPYTREE_SHARE} \* ${DATADIR}/database "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/graph/ && ${COPYTREE_SHARE} \* ${DATADIR}/graph "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/parsers/ && ${COPYTREE_SHARE} \* ${DATADIR}/parsers "! -name *\.pl")
	${INSTALL_SCRIPT} ${WRKSRC}/data/generate.pl ${DATADIR}/data/
.for f in ${DB_SCRIPTS}
		${INSTALL_SCRIPT} ${WRKSRC}/src/perl/database/${f} ${DATADIR}/database/${f}
.endfor
.for f in ${GRAPH_SCRIPTS}
		${INSTALL_SCRIPT} ${WRKSRC}/src/perl/graph/${f} ${DATADIR}/graph/${f}
.endfor
.for f in ${PARSERS}
		${INSTALL_SCRIPT} ${WRKSRC}/src/perl/parsers/${f} ${DATADIR}/parsers/${f}
.endfor

.include <bsd.port.mk>

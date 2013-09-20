# Created by: pauls
# $FreeBSD$

PORTNAME=	afterglow
PORTVERSION=	1.6.2
CATEGORIES=	security graphics net-mgmt
MASTER_SITES=	SF/${PORTNAME}/AfterGlow%201.x/${PORTVERSION}

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Collection of graph-generating scripts

LICENSE=	GPLv2

RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-IP-Anonymous>=0:${PORTSDIR}/net/p5-IP-Anonymous

NO_BUILD=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/data
	${MKDIR} ${DATADIR}/charts
	${MKDIR} ${DATADIR}/graph
	${MKDIR} ${DATADIR}/loganalysis
	${MKDIR} ${DATADIR}/parsers
	(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${DATADIR}/data "! -name generate.pl")
	(cd ${WRKSRC}/data/ && ${COPYTREE_BIN} \* ${DATADIR}/data "-name generate.pl")
	(cd ${WRKSRC}/src/perl/charts/ && ${COPYTREE_SHARE} \* ${DATADIR}/charts "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/charts/ && ${COPYTREE_BIN} \* ${DATADIR}/charts "-name *\.pl")
	(cd ${WRKSRC}/src/perl/graph/ && ${COPYTREE_SHARE} \* ${DATADIR}/graph "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/graph/ && ${COPYTREE_BIN} \* ${DATADIR}/graph "-name *\.pl")
	(cd ${WRKSRC}/src/perl/loganalysis/ && ${COPYTREE_SHARE} \* ${DATADIR}/loganalysis "! ( -name *\.pl -or -name *\.sh )")
	(cd ${WRKSRC}/src/perl/loganalysis/ && ${COPYTREE_BIN} \* ${DATADIR}/loganalysis "( -name *\.pl -or -name *\.sh )")
	(cd ${WRKSRC}/src/perl/parsers/ && ${COPYTREE_SHARE} \* ${DATADIR}/parsers "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/parsers/ && ${COPYTREE_BIN} \* ${DATADIR}/parsers "-name *\.pl")

.include <bsd.port.mk>

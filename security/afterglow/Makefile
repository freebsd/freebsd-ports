# Created by: pauls
# $FreeBSD$

PORTNAME=	afterglow
PORTVERSION=	1.6.2
CATEGORIES=	security graphics net-mgmt
MASTER_SITES=	SF/${PORTNAME}/AfterGlow%201.x/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Collection of graph-generating scripts

LICENSE=	GPLv2

RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-IP-Anonymous>=0:${PORTSDIR}/net/p5-IP-Anonymous

PORTSCOUT=	skipv:2.0
NO_BUILD=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	${MKDIR} ${STAGEDIR}${DATADIR}/charts
	${MKDIR} ${STAGEDIR}${DATADIR}/graph
	${MKDIR} ${STAGEDIR}${DATADIR}/loganalysis
	${MKDIR} ${STAGEDIR}${DATADIR}/parsers
	(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/data "! -name generate.pl")
	(cd ${WRKSRC}/data/ && ${COPYTREE_BIN} \* ${STAGEDIR}${DATADIR}/data "-name generate.pl")
	(cd ${WRKSRC}/src/perl/charts/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/charts "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/charts/ && ${COPYTREE_BIN} \* ${STAGEDIR}${DATADIR}/charts "-name *\.pl")
	(cd ${WRKSRC}/src/perl/graph/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/graph "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/graph/ && ${COPYTREE_BIN} \* ${STAGEDIR}${DATADIR}/graph "-name *\.pl")
	(cd ${WRKSRC}/src/perl/loganalysis/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/loganalysis "! ( -name *\.pl -or -name *\.sh )")
	(cd ${WRKSRC}/src/perl/loganalysis/ && ${COPYTREE_BIN} \* ${STAGEDIR}${DATADIR}/loganalysis "( -name *\.pl -or -name *\.sh )")
	(cd ${WRKSRC}/src/perl/parsers/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/parsers "! -name *\.pl")
	(cd ${WRKSRC}/src/perl/parsers/ && ${COPYTREE_BIN} \* ${STAGEDIR}${DATADIR}/parsers "-name *\.pl")

.include <bsd.port.mk>

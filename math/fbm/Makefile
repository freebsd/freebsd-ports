# New ports collection makefile for:	fbm
# Date created:         31 June 2003
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	fbm
PORTVERSION=	20041110
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.cs.utoronto.ca/pub/radford/
DISTNAME=	${PORTNAME}.2004-11-10
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible Bayesian Modeling and Markov Chain Sampling

NO_LATEST_LINK=	yes
USE_REINPLACE=	yes

SCRIPTS =	bvg-circ bvg-wrap dist-circ dist-wrap gp-circ	\
		gp-wrap dft-circ dft-wrap mix-circ mix-wrap 	\
		net-circ net-wrap
PROGRAMS =	bvg-grad-test bvg-hist bvg-initial bvg-mc	\
		bvg-plt bvg-spec bvg-stepsizes bvg-tbl calc	\
		combine data-spec dist-display dist-est		\
		dist-gen dist-genp dist-grad-test dist-hist	\
		dist-initial dist-mc dist-plt dist-spec 	\
		dist-stepsizes dist-tbl extract	find-min 	\
		dft-cases dft-dendrogram dft-display dft-gen	\
		dft-hist dft-mc dft-plt dft-pred dft-spec 	\
		dft-tbl						\
		gp-cov gp-display gp-eigen gp-eval gp-gen 	\
		gp-genp gp-grad-test gp-hist gp-mc gp-plt 	\
		gp-pred gp-spec gp-stepsizes gp-tbl grid 	\
		log-append log-copy log-equal log-last		\
		log-records mc-ais mc-spec mc-temp-filter	\
		mc-temp-sched mix-cases mix-display mix-gen	\
		mix-hist mix-mc mix-plt mix-spec mix-tbl	\
		model-spec net-display net-dvar net-eval	\
		net-gd net-gen net-genp net-grad-test net-hist	\
		net-mc net-plt net-pred net-rej net-spec	\
		net-stepsizes net-tbl rand-seed series
OTHER=		dft-genp mix-genp

post-patch:
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g;' ${WRKSRC}/make.include
	@${REINPLACE_CMD} -e 's+%%CFLAGS%%+${CFLAGS}+g;' ${WRKSRC}/make.include
do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${SH} make-all)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${SH} install-arch)
.for s in ${SCRIPTS}
	@${REINPLACE_CMD} -e 's+/bin/bash+ ${SH}+;s+exit -1+exit 1+'	\
		${WRKSRC}/bin.${ARCH}/${s}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin.${ARCH}/${s} ${PREFIX}/bin
.endfor
.for i in ${PROGRAMS}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin.${ARCH}/${i} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/share/fbm
	@${INSTALL_DATA} ${WRKSRC}/util/randfile ${PREFIX}/share/fbm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.for i in make-html make-manual rm-html
	@${RM}  ${DOCSDIR}/${i}
.endfor
	@${MKDIR} ${DOCSDIR}/html
	@${MV} ${DOCSDIR}/*.html ${DOCSDIR}/html
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/ex-* ${EXAMPLESDIR}
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>

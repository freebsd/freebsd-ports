# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	words
PORTVERSION=	1.97F
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://archives.nd.edu/whitaker/
DISTNAME=	${PORTNAME}all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Latin-English Dictionary Program

LICENSE=	PD

USES=		ada zip
NO_WRKSUBDIR=	yes
GNATMAKE=	${SETENV} ${MAKE_ENV} gnatmake

OPTIONS_DEFINE=	DOCS

do-build:
	@cd ${WRKSRC} && \
		${GNATMAKE} -O3 words ${GNATLINK_ARGS} && \
		${GNATMAKE} makedict && \
		${GNATMAKE} makestem && \
		${GNATMAKE} makeefil && \
		${GNATMAKE} makeinfl && \
		${ECHO_CMD} G | ./makedict DICTLINE.GEN && \
		${ECHO_CMD} G | ./makestem STEMLIST.GEN && \
		./makeefil EWDSLIST.GEN && \
		./makeinfl INFLECTS.LAT
	@${CAT} ${FILESDIR}/words | ${SED} -e 's|%%DATADIR%%|${DATADIR}|' > ${WRKDIR}/words.sh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/words ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/DICTFILE.GEN ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/STEMFILE.GEN ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/INDXFILE.GEN ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/EWDSFILE.GEN ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/INFLECTS.SEC ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ADDONS.LAT ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/UNIQUES.LAT ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/words.sh ${STAGEDIR}${PREFIX}/bin/words

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/wordsdoc.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

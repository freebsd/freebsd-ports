# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	words
PORTVERSION=	1.97F
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://archives.nd.edu/whitaker/
DISTNAME=	${PORTNAME}all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Latin-English Dictionary Program

USES=		ada
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
GNATMAKE=	env ${MAKE_ENV} gnatmake

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

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
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/words ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/DICTFILE.GEN ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/STEMFILE.GEN ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/INDXFILE.GEN ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/EWDSFILE.GEN ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/INFLECTS.SEC ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ADDONS.LAT ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/UNIQUES.LAT ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/words.sh ${PREFIX}/bin/words
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/wordsdoc.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>

# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	words
PORTVERSION=	1.97F
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://archives.nd.edu/whitaker/
DISTNAME=	${PORTNAME}all

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Latin-English Dictionary Program

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	All parts of the WORDS system, source code and data files, \
		are made freely available to anyone that wishes to use them, \
		for whatever purpose.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		ada zip
NO_WRKSUBDIR=	yes
GNATMAKE=	env ${MAKE_ENV} gnatmake

OPTIONS_DEFINE=	DOCS

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
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/words ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/DICTFILE.GEN ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/STEMFILE.GEN ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/INDXFILE.GEN ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/EWDSFILE.GEN ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/INFLECTS.SEC ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ADDONS.LAT ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/UNIQUES.LAT ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/words.sh ${STAGEDIR}${PREFIX}/bin/words
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/wordsdoc.htm ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

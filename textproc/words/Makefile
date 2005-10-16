# New ports collection makefile for:	words
# Date created:		2 January 2004
# Whom:			Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	words
PORTVERSION=	1.97E
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://users.erols.com/whitaker/
DISTNAME=	${PORTNAME}all
EXTRACT_SUFX=	.zip

MAINTAINER=	llwang@infor.org
COMMENT=	A Latin-English Dictionary Program

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat
.if defined(PACKAGE_BUILDING)
STATIC=		yes
.endif
.if defined(STATIC)
GNATLINK_ARGS=	-largs -static
.else
LIB_DEPENDS=	gnat-3.15.1:${PORTSDIR}/lang/gnat
.endif

USE_ZIP=	yes
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes

GNATMAKE=	gnatmake

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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/wordsdoc.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>

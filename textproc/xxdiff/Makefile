# New ports collection makefile for:	xxdiff
# Date created:				11 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	xxdiff
PORTVERSION=	3.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QT interface to view/merge differences between 2 or 3 files

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

QMAKE=		${LOCALBASE}/bin/qmake
SPEC=		${LOCALBASE}/share/qt/mkspecs/freebsd-g++
USE_BZIP2=	yes
USE_BISON=	build
USE_GMAKE=	yes
USE_QT_VER=	3
MAKE_ENV+=	QTDIR=${QT_PREFIX}
BUILD_WRKSRC=	${WRKSRC}/src

DOCFILES=	xxdiff-doc.html xxdiff-integration.html xxdiff-scripts.html xxdiff-secrets.html \
		equals.png horiz.png perhunk.png rma.png screenshot-sql-schema-compare.png select.png
SSDIR=		${DOCSDIR}/screenshots
SSFILES=	allindex.cidx allindex.html dirindex.html sortindex.html \
		${SSNAPS_EXT:S/^/xxdiff-snap-/}
SSNAPS=		about dirs2 doc files2 files3 merged opt1 opt2 opt3 opt4 opt5
SSNAPS_EXT=	${SSNAPS:S/$/--thumb.jpg/} ${SSNAPS:S/$/.desc/} \
		${SSNAPS:S/$/.html/} ${SSNAPS:S/$/.jpg/}

PLIST_FILES=	bin/xxdiff
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's!flex!${LOCALBASE}/bin/flex!' ${BUILD_WRKSRC}/xxdiff.pro
	@${REINPLACE_CMD} -e 's!?= /usr/qt/3!= ${LOCALBASE}!' ${BUILD_WRKSRC}/Makefile.bootstrap

pre-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} QMAKESPEC=${SPEC} ${MAKE} -f Makefile.bootstrap ${MAKE_ARGS} Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xxdiff ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR} ${SSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
	${INSTALL_DATA} ${SSFILES:S,^,${WRKSRC}/doc/screenshots/,} ${SSDIR}/
.endif

.include <bsd.port.mk>

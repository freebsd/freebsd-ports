# New ports collection makefile for:	xxdiff
# Date created:				11 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	xxdiff
PORTVERSION=	3.0.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	QT interface to view/merge differences between 2 or 3 files

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

USE_BISON=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
TMAKEENV=	TMAKEPATH=${LOCALBASE}/share/tmake/freebsd-g++ QTDIR=${X11BASE}
MAKE_ENV+=	QTDIR=${X11BASE} PTHREAD_LIBS=${PTHREAD_LIBS}
WRKSRC=	${WRKDIR}/xxdiff-${PORTVERSION}/src

DOCFILES=	xxdiff-cvs-diff.html xxdiff-doc.html \
		xxdiff-encrypted.html xxdiff-find-grep-sed.html \
		xxdiff-integration.html xxdiff-match.html \
		xxdiff-patch-UNFINISHED.html xxdiff-secrets.html \
		equals.png select.png

SSDIR=		${DOCSDIR}/screenshots
SSFILES=	allindex.cidx allindex.html dirindex.html sortindex.html \
		xxdiff-snap-about--thumb.jpg xxdiff-snap-about.desc \
		xxdiff-snap-about.html xxdiff-snap-about.jpg \
		xxdiff-snap-dirs2--thumb.jpg xxdiff-snap-dirs2.desc \
		xxdiff-snap-dirs2.html xxdiff-snap-dirs2.jpg \
		xxdiff-snap-doc--thumb.jpg xxdiff-snap-doc.desc \
		xxdiff-snap-doc.html xxdiff-snap-doc.jpg \
		xxdiff-snap-files2--thumb.jpg xxdiff-snap-files2.desc \
		xxdiff-snap-files2.html xxdiff-snap-files2.jpg \
		xxdiff-snap-files3--thumb.jpg xxdiff-snap-files3.desc \
		xxdiff-snap-files3.html xxdiff-snap-files3.jpg \
		xxdiff-snap-merged--thumb.jpg xxdiff-snap-merged.desc \
		xxdiff-snap-merged.html xxdiff-snap-merged.jpg \
		xxdiff-snap-opt1--thumb.jpg xxdiff-snap-opt1.desc \
		xxdiff-snap-opt1.html xxdiff-snap-opt1.jpg \
		xxdiff-snap-opt2--thumb.jpg xxdiff-snap-opt2.desc \
		xxdiff-snap-opt2.html xxdiff-snap-opt2.jpg \
		xxdiff-snap-opt3--thumb.jpg xxdiff-snap-opt3.desc \
		xxdiff-snap-opt3.html xxdiff-snap-opt3.jpg \
		xxdiff-snap-opt4--thumb.jpg xxdiff-snap-opt4.desc \
		xxdiff-snap-opt4.html xxdiff-snap-opt4.jpg \
		xxdiff-snap-opt5--thumb.jpg xxdiff-snap-opt5.desc \
		xxdiff-snap-opt5.html xxdiff-snap-opt5.jpg

.include <bsd.port.pre.mk>

do-build:
	(cd ${WRKSRC}; ${SETENV} ${TMAKEENV} tmake -o Makefile xxdiff.pro)
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/xxdiff ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${SSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/../doc/,} ${DOCSDIR}
	${INSTALL_DATA} ${SSFILES:S,^,${WRKSRC}/../doc/screenshots/,} ${SSDIR}
.endif

.include <bsd.port.post.mk>

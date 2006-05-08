# New ports collection makefile for:	xxdiff
# Date created:				11 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	xxdiff
PORTVERSION=	3.0.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	QT interface to view/merge differences between 2 or 3 files

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

USE_BISON=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
TMAKEENV=	TMAKEPATH=${LOCALBASE}/share/tmake/freebsd-g++ QTDIR=${X11BASE}
MAKE_ENV+=	QTDIR=${X11BASE} PTHREAD_LIBS=${PTHREAD_LIBS}
WRKSRC=		${WRKDIR}/xxdiff-${PORTVERSION}/src

DOCFILES=	xxdiff-cvs-diff.html xxdiff-doc.html \
		xxdiff-encrypted.html xxdiff-find-grep-sed.html \
		xxdiff-integration.html xxdiff-match.html \
		xxdiff-patch-UNFINISHED.html xxdiff-secrets.html \
		equals.png select.png

SSDIR=		${DOCSDIR}/screenshots
SSFILES=	allindex.cidx allindex.html dirindex.html sortindex.html \
		${SSSNAPS:S/^/xxdiff-snap-/}
SSSNAPS=	about--thumb.jpg about.desc about.html about.jpg dirs2--thumb.jpg dirs2.desc \
		dirs2.html dirs2.jpg doc--thumb.jpg doc.desc doc.html doc.jpg files2--thumb.jpg \
		files2.desc files2.html files2.jpg files3--thumb.jpg files3.desc files3.html \
		files3.jpg merged--thumb.jpg merged.desc merged.html merged.jpg opt1--thumb.jpg \
		opt1.desc opt1.html opt1.jpg opt2--thumb.jpg opt2.desc opt2.html opt2.jpg \
		opt3--thumb.jpg opt3.desc opt3.html opt3.jpg opt4--thumb.jpg opt4.desc opt4.html \
		opt4.jpg opt5--thumb.jpg opt5.desc opt5.html opt5.jpg

PLIST_FILES=	bin/xxdiff
PORTDOCS=	*

.include <bsd.port.pre.mk>

do-build:
	(cd ${WRKSRC}; ${SETENV} ${TMAKEENV} tmake -o Makefile xxdiff.pro)
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/xxdiff ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${SSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/../doc/,} ${DOCSDIR}/
	${INSTALL_DATA} ${SSFILES:S,^,${WRKSRC}/../doc/screenshots/,} ${SSDIR}/
.endif

.include <bsd.port.post.mk>

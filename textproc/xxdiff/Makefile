# New ports collection makefile for:	xxdiff
# Date created:				11 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	xxdiff
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL:S/%SUBDIR%/petef/g} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xxdiff-${PORTVERSION}.html
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	petef@FreeBSD.org
COMMENT=	QT interface to view/merge differences between 2 or 3 files

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

USE_BISON=	yes
USE_GMAKE=	yes
USE_QT_VER=	2
TMAKEENV=	TMAKEPATH=${LOCALBASE}/share/tmake/freebsd-g++ QTDIR=${X11BASE}
MAKE_ENV+=	QTDIR=${X11BASE} PTHREAD_LIBS=${PTHREAD_LIBS}
WRKSRC=	${WRKDIR}/xxdiff-${PORTVERSION}/src

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

do-build:
	(cd ${WRKSRC}; ${SETENV} ${TMAKEENV} tmake -o Makefile xxdiff.pro)
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxdiff ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/xxdiff-${PORTVERSION}.html \
		${DOCSDIR}/xxdiff.html
.endif

.include <bsd.port.post.mk>

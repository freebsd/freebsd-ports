# New ports collection makefile for:	xxdiff
# Date created:				11 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	xxdiff
PORTVERSION=	2.0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@FreeBSD.org

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

USE_GMAKE=	yes
USE_QT_VER=	2
TMAKEENV=	TMAKEPATH=${LOCALBASE}/share/tmake/freebsd-g++ QTDIR=${X11BASE}
MAKE_ENV+=	QTDIR=${X11BASE} PTHREAD_LIBS=${PTHREAD_LIBS}
WRKSRC=	${WRKDIR}/xxdiff-${PORTVERSION}/src

do-build:
	(cd ${WRKSRC}; ${SETENV} ${TMAKEENV} tmake -o Makefile xxdiff.pro)
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xxdiff ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${WRKSRC}/xxdiff --help-html > ${WRKDIR}/xxdiff.html
	${INSTALL_DATA} ${WRKDIR}/xxdiff.html ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	unroff
# Date created:		18 Feb 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	unroff
PORTVERSION=	1.0.2
CATEGORIES=	textproc
MASTER_SITES=	${UNROFF_SITE}/dist/ \
		${UNROFF_SITE}/contrib/
DISTNAME=	${PORTNAME}-1.0
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PATCH1} ${PATCH2}

MAINTAINER=	ports@freebsd.org
COMMENT=	A programmable troff translator with backend for HTML

RUN_DEPENDS=	elk:${PORTSDIR}/lang/elk
BUILD_DEPENDS=	elk:${PORTSDIR}/lang/elk

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	unroff
PATCH_STRIP=	-p1

UNROFF_SITE=	http://www-rn.informatik.uni-bremen.de/software/unroff
PATCH1=		me-misc-patch
PATCH2=		misc-patch-2

BUILD_WRKSRC=	${WRKSRC}/src

MAN1=		unroff.1 unroff-html.1 unroff-html-man.1 \
		unroff-html-me.1 unroff-html-ms.1

pre-patch:
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@(cd ${_DISTDIR}; \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying distribution patch ${PATCH1}" ; \
		fi; \
		${PATCH} ${PATCH_DIST_ARGS} -p0 < ${PATCH1}; \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying distribution patch ${PATCH2}" ; \
		fi; \
		${PATCH} ${PATCH_DIST_ARGS} -p1 < ${PATCH2})

do-install:
	@${MKDIR} ${DATADIR}/misc
	${INSTALL_PROGRAM} ${WRKSRC}/src/unroff ${PREFIX}/bin/unroff
	${CP} -R ${WRKSRC}/scm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tmac.hyper ${WRKSRC}/misc/sample.unroff ${DATADIR}/misc
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.ms ${DOCSDIR}
.endif

.include <bsd.port.mk>

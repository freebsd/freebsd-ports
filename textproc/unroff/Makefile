# New ports collection makefile for:	unroff
# Version required:	1.0
# Date created:		18 Feb 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.5 1997/03/06 12:24:49 wosch Exp $
#

DISTNAME=	unroff-1.0
PKGNAME=	unroff-1.0.2
CATEGORIES=	textproc
MASTER_SITES=	${UNROFF_SITE}/dist/ \
		${UNROFF_SITE}/contrib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PATCH1} ${PATCH2}

MAINTAINER=	wosch@freebsd.org

RUN_DEPENDS=	elk:${PORTSDIR}/lang/elk
BUILD_DEPENDS=	elk:${PORTSDIR}/lang/elk

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	unroff
PATCH_STRIP=	-p1

UNROFF_SITE=	http://www-rn.informatik.uni-bremen.de/software/unroff
PATCH1=		me-misc-patch
PATCH2=		misc-patch-2

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

.include <bsd.port.mk>

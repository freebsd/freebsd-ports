# New ports collection makefile for:    ru-elm
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PKGNAME=        ru-elm-2.4ME
CATEGORIES=     russian mail

RUN_DEPENDS+=   elm:${PORTSDIR}/mail/elm

MAINTAINER=     ache@FreeBSD.org

EXTRACT_ONLY=   # empty
NO_WRKSUBDIR=   YES
NO_BUILD=       YES

do-fetch:

do-install:
	${GREP} -q -i koi8 ${PREFIX}/lib/elm.rc || \
		( \
		${ECHO_MSG} "charset=KOI8-R"; \
		${ECHO_MSG} "displaycharset=KOI8-R"; \
		) >> \
		${PREFIX}/lib/elm.rc

.include <bsd.port.mk>

# New ports collection makefile for:    ru-elm
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.10 1996/12/03 15:25:18 ache Exp $
#

PKGNAME=        ru-elm-2.4ME
CATEGORIES=     russian mail

RUN_DEPENDS+=   elm:${PORTSDIR}/mail/elm

MAINTAINER=     ache@FreeBSD.org

NO_EXTRACT=     YES
NO_WRKDIR=      YES
NO_BUILD=       YES

do-fetch:

do-install:
	grep -q -i koi8 ${PREFIX}/lib/elm.rc || \
		( \
		echo "charset=KOI8-R"; \
		echo "displaycharset=KOI8-R"; \
		) >> \
		${PREFIX}/lib/elm.rc

.include <bsd.port.mk>

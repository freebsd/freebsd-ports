# New ports collection makefile for:    ru-elm
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1995/12/20 06:58:00 ache Exp $
#

PKGNAME=        ru-elm
CATEGORIES+=    russian mail
RUN_DEPENDS+=   elm:${PORTSDIR}/mail/elm
MAINTAINER=     ache@FreeBSD.org
NO_EXTRACT=     YES
NO_WRKDIR=      YES
NO_CONFIGURE=   YES
NO_PATCH=       YES
NO_BUILD=       YES

do-fetch:

do-install:
	grep -q -i koi8 ${PREFIX}/lib/elm.rc || \
		(echo "charset=KOI8-R"; echo "displaycharset=KOI8-R";) >> \
		${PREFIX}/lib/elm.rc

.include <bsd.port.mk>

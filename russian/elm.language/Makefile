# New ports collection makefile for:    ru-elm+mime
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1995/12/03 01:31:38 ache Exp $
#

PKGNAME=        ru-elm+mime
CATEGORIES+=    russian mail
RUN_DEPENDS+=   elm:${PORTSDIR}/mail/elm+mime
# A little trick here, it can be elm without mime
RUN_DEPENDS+=   metamail:${PORTSDIR}/mail/elm+mime
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

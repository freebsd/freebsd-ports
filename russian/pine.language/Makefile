# New ports collection makefile for:    ru-pine
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1996/12/03 15:31:21 ache Exp $
#

PKGNAME=        ru-pine-3.95
CATEGORIES=     russian mail

MAINTAINER=     ache@FreeBSD.org

RUN_DEPENDS=    pine:${PORTSDIR}/mail/pine

NO_EXTRACT=     YES
NO_WRKDIR=      YES
NO_CONFIGURE=   YES
NO_PATCH=       YES
NO_BUILD=       YES

do-fetch:

do-install:
	grep -q -i koi8 ${PREFIX}/etc/pine.conf || \
		cat ${FILESDIR}/pine.add >> \
		${PREFIX}/etc/pine.conf

.include <bsd.port.mk>

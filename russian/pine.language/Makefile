# New ports collection makefile for:    ru-pine
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.9 1996/11/18 11:39:02 asami Exp $
#

PKGNAME=        ru-pine-3.95
CATEGORIES=     russian mail

RUN_DEPENDS+=   pine:${PORTSDIR}/mail/pine

MAINTAINER=     ache@FreeBSD.org

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

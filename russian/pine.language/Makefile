# New ports collection makefile for:    ru-pine
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.2 1996/12/04 00:04:12 asami Exp $
#

PKGNAME=        ru-pine-3.95
CATEGORIES=     russian mail

MAINTAINER=     ache@FreeBSD.org

RUN_DEPENDS=    pine:${PORTSDIR}/mail/pine

NO_EXTRACT=     YES
NO_WRKDIR=      YES
NO_BUILD=       YES

do-fetch:

do-install:
	grep -q -i koi8 ${PREFIX}/etc/pine.conf || \
		cat ${FILESDIR}/pine.add >> \
		${PREFIX}/etc/pine.conf

.include <bsd.port.mk>

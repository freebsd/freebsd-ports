# New ports collection makefile for:    ru-pine
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.4 1998/07/25 12:35:50 asami Exp $
#

PKGNAME=        ru-pine-3.96
CATEGORIES=     russian mail

MAINTAINER=     ache@FreeBSD.org

RUN_DEPENDS=    pine:${PORTSDIR}/mail/pine3

EXTRACT_ONLY=   # empty
NO_WRKSUBDIR=   YES
NO_BUILD=       YES

do-fetch:

do-install:
	grep -q -i koi8 ${PREFIX}/etc/pine.conf || \
		cat ${FILESDIR}/pine.add >> \
		${PREFIX}/etc/pine.conf

.include <bsd.port.mk>

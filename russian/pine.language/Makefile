# New ports collection makefile for:    ru-pine
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1998/12/01 11:29:29 asami Exp $
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
		${CAT} ${FILESDIR}/pine.add >> \
		${PREFIX}/etc/pine.conf

.include <bsd.port.mk>

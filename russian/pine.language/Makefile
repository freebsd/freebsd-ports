# New ports collection makefile for:    ru-pine
# Date created:         2 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
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
	${GREP} -q -i koi8 ${PREFIX}/etc/pine.conf || \
		${CAT} ${FILESDIR}/pine.add >> \
		${PREFIX}/etc/pine.conf

.include <bsd.port.mk>

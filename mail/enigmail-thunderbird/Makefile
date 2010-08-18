# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTVERSION=	1.1.2

COMMENT=	A GnuPG extension for the Thunderbird mail client

EXTRACT_DEPENDS=autoconf-2.13:${PORTSDIR}/devel/autoconf213

MASTERDIR=	${.CURDIR}/../enigmail

GECKO=		thunderbird
GECKO_PORTDIR=	mail/${GECKO}
GECKO_EXTDIR=	comm-1.9.2

MAKE_JOBS_UNSAFE=	yes

.include "${MASTERDIR}/Makefile"

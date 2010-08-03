# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTVERSION=	0.96.0
PORTREVISION=	1

COMMENT=	A GnuPG extension for the Thunderbird mail client

IGNORE=		Does not work with Thunderbird 3.1

MASTERDIR=	${.CURDIR}/../enigmail

GECKO=		thunderbird
GECKO_PORTDIR=	mail/${GECKO}
GECKO_WRKSRC=	${WRKDIR}/../../../${GECKO_PORTDIR}/work/mozilla

.include "${MASTERDIR}/Makefile"

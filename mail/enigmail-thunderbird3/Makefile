# New ports collection makefile for:	enigmail
# Date created:			30 December 2009
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTVERSION=	1.1.2

COMMENT=	A GnuPG extension for the Thunderbird mail client

EXTRACT_DEPENDS=autoconf-2.13:${PORTSDIR}/devel/autoconf213

MASTERDIR=	${.CURDIR}/../enigmail

GECKO=		thunderbird3
GECKO_PORTDIR=	mail/${GECKO}
GECKO_EXTDIR=	comm-1.9.2

PORTSCOUT=	ignore:1

.include "${MASTERDIR}/Makefile"

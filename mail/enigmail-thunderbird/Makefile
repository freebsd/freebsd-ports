# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

COMMENT=	A GnuPG extension for the Thunderbird mail client

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip \
		yasm:${PORTSDIR}/devel/yasm

MASTERDIR=	${.CURDIR}/../enigmail

GECKO=		thunderbird
GECKO_PORTDIR=	mail/${GECKO}
GECKO_EXTDIR=	comm-release

.include "${MASTERDIR}/Makefile"

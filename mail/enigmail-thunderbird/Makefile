# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-thunderbird

COMMENT=	A GnuPG extension for the Thunderbird mail client

EXTRACT_DEPENDS=${WRKDIR}/../../../${LOCAL_SRCDIR}/work/mozilla/Makefile:${PORTSDIR}/${LOCAL_SRCDIR}:configure
RUN_DEPENDS=	thunderbird:${PORTSDIR}/${LOCAL_SRCDIR}

IGNORE=		cannot be installed globally with the new thunderbird 0.7+ extension manager

IPCVERSION=	1.0.7

MASTERDIR=	${.CURDIR}/../enigmail

PKGINSTALL=	${.CURDIR}/pkg-install
PKGDEINSTALL=	${.CURDIR}/pkg-deinstall
PKGMESSAGE=	${.CURDIR}/pkg-message

LOCAL_SRCDIR=	mail/thunderbird
LOCAL_SUBDIR=	lib/thunderbird/lib/thunderbird-0.7

.include "${MASTERDIR}/Makefile"

# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-thunderbird

COMMENT=	A GnuPG extension for the Thunderbird mail client

EXTRACT_DEPENDS=${LOCAL_SRCDIR}/work/mozilla/Makefile:${LOCAL_SRCDIR}:configure
RUN_DEPENDS=	thunderbird:${LOCAL_SRCDIR}

MASTERDIR=	${.CURDIR}/../enigmail

PKGINSTALL=	${.CURDIR}/pkg-install
PKGDEINSTALL=	${.CURDIR}/pkg-deinstall

LOCAL_SRCDIR=	${PORTSDIR}/mail/mozilla-thunderbird
LOCAL_SUBDIR=	lib/thunderbird/lib/mozilla-1.6b

.include "${MASTERDIR}/Makefile"

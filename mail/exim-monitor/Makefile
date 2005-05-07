# New ports collection makefile for:	exim-monitor
# Date created:		27 August 2001
# Whom:			sheldonh@FreeBSD.org
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-monitor

COMMENT=	The Exim monitor for the Exim MTA

MASTERDIR=	${.CURDIR}/../exim
PKGDIR=		${.CURDIR}

BROKEN=		Incomplete pkg-plist

EXIMON_ONLY=	yes

# This dependency is disabled, because it prevents package users from
# using the exim-monitor package with any of the exim slave packages.
#
#RUN_DEPENDS=	${LOCALBASE}/sbin/exim:${PORTSDIR}/mail/exim

.include "${MASTERDIR}/Makefile"

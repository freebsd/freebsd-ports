# New ports collection makefile for:	amanda
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	${MASTERPORTNAME:S/-server/-client/g}
PORTREVISION=	3

MASTERDIR=	${.CURDIR}/../amanda-server
COMMENT=	The Advanced Maryland Automatic Network Disk Archiver (client)
PKGINSTALL=	mustnotexist
PLIST=		${PKGDIR}/pkg-plist.client

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"

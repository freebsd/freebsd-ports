# New ports collection makefile for:	amanda
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-client
PORTREVISION=	3

COMMENT=	The Advanced Maryland Automatic Network Disk Archiver (client)

MASTERDIR=	${.CURDIR}/../amanda-server
PKGINSTALL=	mustnotexist

PLIST=		${PKGDIR}/pkg-plist.client

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"

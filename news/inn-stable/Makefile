# New ports collection makefile for:	inn
# Date created:		20 Oct 1994 (1.4), 18 Dec 1996 (1.5.1), 14 Feb 1999 (2.2)
# Whom:			torstenb
#
# $FreeBSD$
#

PORTVERSION=	${SNAPSHOT}
PORTREVISION=	0			# Ensure master is overridden
MASTER_SITE_ISC?=			# Empty
MASTER_SITES=	${MASTER_SITE_ISC:C/$/ ${MASTER_SITE_LOCAL:C/%SUBDIR%/shaun/g}/1}
MASTER_SITE_SUBDIR=	inn/snapshots
PKGNAMESUFFIX=	-${BRANCH}
DISTNAME=	${PORTNAME}-${BRANCH:U}-${SNAPSHOT}

BRANCH=		stable
SNAPSHOT=	20061024

CONFLICTS=	inn-2.[0-9]* inn-current-[0-9]

PATCHDIR=	${.CURDIR}/files
MD5_FILE=	${.CURDIR}/distinfo

MASTERDIR=	${.CURDIR}/../inn

BROKEN=		Fails to patch
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

.include "${MASTERDIR}/Makefile"

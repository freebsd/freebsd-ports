# New ports collection makefile for:	inn
# Date created:				2003
# Whom:					clement
#
# $FreeBSD$
#

PORTVERSION=	${SNAPSHOT}
PORTREVISION=	1			# Ensure master is overridden
MASTER_SITE_ISC?=			# Empty
MASTER_SITES=	${MASTER_SITE_ISC:C/$/ ${MASTER_SITE_LOCAL:C/%SUBDIR%/shaun/g}/1}
MASTER_SITE_SUBDIR=	inn/snapshots
PKGNAMESUFFIX=	-${BRANCH}
DISTNAME=	${PORTNAME}-${BRANCH:U}-${SNAPSHOT}

BROKEN=		Does not install

BRANCH=		current
SNAPSHOT=	20061024

CONFLICTS=	inn-2.[0-9]* inn-stable-[0-9]*

PATCHDIR=	${.CURDIR}/files
MD5_FILE=	${.CURDIR}/distinfo

MASTERDIR=	${.CURDIR}/../inn

.include "${MASTERDIR}/Makefile"

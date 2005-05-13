# New ports collection makefile for:	ru-unzip
# Date created:		4 May 2005
# Whom:			den
#
# $FreeBSD$
#

CATEGORIES=	russian archivers

MAINTAINER=	den@FreeBSD.org
COMMENT=	Unzip with CP866 and KOI8-R support

CONFLICTS=	unzip-[0-9]* [a-z][a-z]-unzip-[0-9]*

EXTRA_PATCHES=	${.CURDIR}/files/patch-ebcdic.h

MASTERDIR=	${.CURDIR}/../../archivers/unzip

.include "${MASTERDIR}/Makefile"

# New ports collection makefile for:	ru-bogofilter
# Date created:		18 June 2004
# Whom:			Yar Tikhiy <yar@freebsd.org>
#
# $FreeBSD$
#

CATEGORIES=	russian mail

MAINTAINER=	yar@freebsd.org

BROKEN=		The support for KOI8-R wordlist storage is broken in bogofilter >=0.94.x

CONFLICTS=	bogofilter-[0-9]* bogofilter-tdb-[0-9]* bogofilter-qdbm-[0-9]* bogofilter-sqlite-[0-9]*

CFLAGS+=	-DWINDOWS_1251_to_CYRILLIC

MASTERDIR=	${.CURDIR}/../../mail/bogofilter

.include "${MASTERDIR}/Makefile"

# New ports collection makefile for:	ru-bogofilter
# Date created:		18 June 2004
# Whom:			Yar Tikhiy <yar@freebsd.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../mail/bogofilter

CATEGORIES=	russian mail

MAINTAINER=	yar@freebsd.org

CONFLICTS=	bogofilter-0* bogofilter-tdb* bogofilter-qdbm*

CFLAGS+=	-DWINDOWS_1251_to_CYRILLIC

.include "${MASTERDIR}/Makefile"

# New ports collection makefile for:	ru-bogofilter
# Date created:		18 June 2004
# Whom:			Yar Tikhiy <yar@freebsd.org>
#
# $FreeBSD$
#

CATEGORIES=	russian mail

MAINTAINER=	yar@freebsd.org

DEPRECATED=	mail/bogofilter provides Unicode support through WITH_ICONV

CONFLICTS=	bogofilter-[0-9]* bogofilter-tdb-[0-9]* bogofilter-qdbm-[0-9]* bogofilter-sqlite-[0-9]*

# bogofilter does CP1251->KOI8-R conversion by default since 0.94.13.
# WITH_CP866 tells bogofilter to map KOI8-R, CP1251, and ISO-8859-5 to CP866.
.if defined(WITH_CP866)
CONFIGURE_ARGS+=	--enable-russian
.else
NO_PACKAGE=	Identical to mail/bogofilter by default since 0.94.13
.endif

MASTERDIR=	${.CURDIR}/../../mail/bogofilter

.include "${MASTERDIR}/Makefile"

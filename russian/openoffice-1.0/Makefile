# New ports collection makefile for:	OpenOffice.org for Russian language
# Date created:		Tue Jun 11 16:47:21 UTC 2002
# Whom:		Martin Blapp <mbr@FreeBSD.org> and Mario Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=     russian

.if !defined (LANG) && !defined(USE_LANG)
USE_LANG=	ru_RU.KOI8-R
.endif
LANG_LIST=	ru_RU.KOI8-R uk_UA.KOI8-U
LANG_PKGNAME=	ru
LANG_EXT=	07
LANG_CONFIGURE_ARG=	RUSS
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.0

PATCH_SITES=	http://people.freebsd.org/~mbr/ooo/
PATCHFILES=	patch-translation-ru-1.0.3.bz2

NO_LATEST_LINK=	yes	
.include "${MASTERDIR}/Makefile"

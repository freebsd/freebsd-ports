# New ports collection makefile for:	OpenOffice for Russian language
# Date created:		 Sun Nov 9 9:19:23 2003 JST 
# Whom:		Martin Blapp <mbr@FreeBSD.org>, Mario Ferreira <lioux@FreeBSD.org> and NAKATA Maho <maho@FreeBSD.org>
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
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.1

PATCH_SITES=	http://people.freebsd.org/~mbr/ooo/
PATCHFILES=	patch-translation-ru-1.0.3.bz2

.include "${MASTERDIR}/Makefile"

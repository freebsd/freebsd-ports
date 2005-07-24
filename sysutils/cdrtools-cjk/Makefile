# New ports collection makefile for:	cdrtools-cjk
# Date created:				6 June 2004
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTVERSION=	2.01.${PATCHDATE}
PORTREVISION=	1
CATEGORIES=	sysutils chinese japanese korean audio
PKGNAMEPREFIX=	cjk-

#PATCH_SITES=	http://www.geocities.co.jp/SiliconValley/3657/mkisofs_patch/
PATCH_SITES=	ftp://ftp.zeist.de/pub/distfiles/
PATCHFILES=	noboru_nls_patch_${PATCHDATE}.txt.gz
PATCH_DIST_STRIP=	-p1

CONFLICTS=	cdrtools-*

PATCHDATE=	20041227
MASTERDIR=	${.CURDIR}/../cdrtools
DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"

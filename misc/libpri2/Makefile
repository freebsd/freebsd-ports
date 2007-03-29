# New ports collection makefile for:	libpri
# Date created:				25 Oct 2004
# Whom:					Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	libpri
PORTVERSION=	1.2.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.digium.com/pub/libpri/ \
		ftp://ftp.digium.com/pub/libpri/old/

MAINTAINER=	gonzo@univ.kiev.ua
COMMENT=	A C implementation of the Primary Rate ISDN specification

#PATCHFILES=	${PORTNAME}-${PORTVERSION}-${BRIVER}.patch.gz
#PATCH_SITES=	${MASTER_SITE_LOCAL}
#PATCH_SITE_SUBDIR=	fjoe
#PATCH_DIST_STRIP=	-p1
#BRIVER=		bristuff-0.3.0-PRE-1l

USE_GMAKE=	yes
USE_LDCONFIG=	yes
PLIST_FILES=	include/libpri.h lib/libpri.a lib/libpri.a lib/libpri.so \
		lib/libpri.so.1

NOT_FOR_ARCHS=	alpha

.include <bsd.port.mk>

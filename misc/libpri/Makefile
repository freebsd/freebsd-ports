# New ports collection makefile for:	libpri
# Date created:				25 Oct 2004
# Whom:					Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	libpri
PORTVERSION=	1.4.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.digium.com/pub/libpri/ \
		ftp://ftp.digium.com/pub/libpri/old/

MAINTAINER=	gonzo@univ.kiev.ua
COMMENT=	A C implementation of the Primary Rate ISDN specification

USE_GMAKE=	yes
USE_LDCONFIG=	yes
PLIST_FILES=	include/libpri.h lib/libpri.a lib/libpri.so \
		lib/libpri.so.1

NOT_FOR_ARCHS=	alpha

.include <bsd.port.mk>

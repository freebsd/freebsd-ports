# New ports collection makefile for:	hpijs
# Date created:		1 May 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libijs
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/ijs/download/
DISTNAME=	ijs-${PORTVERSION}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library that supports plugin printer driver for Ghostscript

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAKE_ENV=	SHLIB_VER=${SHLIB_VER}
PLIST_SUB=	SHLIB_VER=${SHLIB_VER}

SHLIB_VER=	1

.include <bsd.port.mk>

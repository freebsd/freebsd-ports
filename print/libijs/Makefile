# New ports collection makefile for:	hpijs
# Date created:		1 May 2002
# Whom:			ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libijs
PORTVERSION=	0.35
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/ijs/download/
DISTNAME=	ijs-${PORTVERSION}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library that supports plugin printer driver for Ghostscript

USE_BZIP2=	yes
USE_GNOME=	gnometarget lthack pkgconfig
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

MAN1=		ijs-config.1

.include <bsd.port.mk>

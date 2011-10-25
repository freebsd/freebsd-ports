# New ports collection makefile for:	libass
# Date created:		2011-03-23
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libass
PORTVERSION=	0.10.0
CATEGORIES=	multimedia devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Portable ASS/SSA subtitle renderer

LICENSE=	ISCL

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		enca.5:${PORTSDIR}/converters/enca \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		expat.6:${PORTSDIR}/textproc/expat2 \
		fribidi.3:${PORTSDIR}/converters/fribidi

USE_GNOME=	pkgconfig gnomehack
USE_XZ=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.mk>

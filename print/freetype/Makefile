# New ports collection makefile for:	freetype
# Version required:	1.2
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $Id: Makefile,v 1.10 1998/12/14 15:39:26 sada Exp $
#

DISTNAME=	freetype-1.2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tux.org/pub/devel/freetype/ \
		ftp://ftp.lerc.nasa.gov/ImageMagick/delegates/ \
		ftp://ftp.wizards.dupont.com/pub/ImageMagick/delegates/ \
		ftp://ftp.kddlabs.co.jp/.6/graphics/freetype/ \
		ftp://ring.aist.go.jp/pub/graphics/freetype/ \
		ftp://ftp.unina.it/pub/Unix/pkgs/font/freetype/

MAINTAINER=	jseger@FreeBSD.org

USE_XLIB=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-nls --enable-static --enable-shared

.include <bsd.port.mk>

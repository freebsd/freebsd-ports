# New ports collection makefile for:	freetype
# Version required:	1.2
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $Id: Makefile,v 1.9 1998/12/14 02:48:02 obrien Exp $
#

DISTNAME=	freetype-1.2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.physiol.med.tu-muenchen.de/pub/freetype/ \
		ftp://ftp.lerc.nasa.gov/ImageMagick/delegates/ \
		ftp://ftp.tux.org/pub/devel/freetype/ \
		ftp://ftp.kddlabs.co.jp/.6/graphics/freetype/ \
		ftp://ring.aist.go.jp/pub/graphics/freetype/

MAINTAINER=	jseger@FreeBSD.org

USE_XLIB=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-nls --enable-static --enable-shared

.include <bsd.port.mk>

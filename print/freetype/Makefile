# New ports collection makefile for:	freetype
# Version required:	1.2
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $Id: Makefile,v 1.8 1998/12/12 20:58:05 jseger Exp $
#

DISTNAME=	freetype-1.2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.physiol.med.tu-muenchen.de/pub/freetype/

MAINTAINER=	jseger@FreeBSD.org

BROKEN=	'fetch from *SINGLE* down site'

USE_XLIB=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-nls --enable-static --enable-shared

.include <bsd.port.mk>

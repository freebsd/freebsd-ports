# New ports collection makefile for:	freetype
# Version required:	1.0
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $Id: Makefile,v 1.4 1998/02/08 02:31:58 jseger Exp $
#

DISTNAME=	freetype-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.physiol.med.tu-muenchen.de/pub/freetype/

MAINTAINER=	jseger@FreeBSD.org

USE_GMAKE=	YES
USE_AUTOCONF=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-nls

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/ttcommon.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/tterror.h ${PREFIX}/include

.include <bsd.port.mk>

# New ports collection makefile for:	freetype
# Version required:	1.0
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $Id: Makefile,v 1.3 1998/01/26 15:34:53 jseger Exp $
#

DISTNAME=	freetype-1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.physiol.med.tu-muenchen.de/pub/freetype/

MAINTAINER=	jseger@FreeBSD.org

USE_GMAKE=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/ttcommon.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/tterror.h ${PREFIX}/include
.include <bsd.port.mk>

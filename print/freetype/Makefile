# New ports collection makefile for:	freetype
# Version required:	October 6, 1997 beta
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $Id: Makefile,v 1.1.1.1 1998/01/24 16:50:41 jseger Exp $
#

DISTNAME=	freetype-beta
PKGNAME=	freetype-971006
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.physiol.med.tu-muenchen.de/pub/freetype/

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=		${WRKDIR}/freetype
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/ttf2bdf/ttf2bdf ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libttf.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.h ${PREFIX}/include
	${LDCONFIG} -m ${PREFIX}/lib
.include <bsd.port.mk>

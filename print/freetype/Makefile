# New ports collection makefile for:	freetype
# Version required:	October 6, 1997 beta
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $Id$
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
	${LDCONFIG} -m ${PREFIX}/lib
.include <bsd.port.mk>

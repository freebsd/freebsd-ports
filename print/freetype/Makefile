# New ports collection makefile for:	freetype
# Version required:	JAN-21-1998 snapshot
# Date created:		January 24, 1998
# Whom:			jseger@FreeBSD.org
#
# $Id: Makefile,v 1.2 1998/01/24 21:51:43 jseger Exp $
#

DISTNAME=	freetype-980121
CATEGORIES=	print
MASTER_SITES=	http://www.freebsd.org/~jseger/

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=		${WRKDIR}/freetype-current
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/ttcommon.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/tterror.h ${PREFIX}/include
.include <bsd.port.mk>

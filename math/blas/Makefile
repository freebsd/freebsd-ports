# New ports collection makefile for:    blas
# Version required:     ?
# Date created:         27 October 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.14 1998/02/09 13:02:03 steve Exp $
#

DISTNAME=	blas
PKGNAME=	blas-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/blas/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}

pre-build:
	${CP} ${FILESDIR}/makefile.lib ${WRKDIR}/Makefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

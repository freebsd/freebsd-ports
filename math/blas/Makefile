# New ports collection makefile for:    blas
# Version required:     ?
# Date created:         27 October 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.16 1998/07/07 19:21:02 scrappy Exp $
#

DISTNAME=	blas
PKGNAME=	blas-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/blas/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/linpack/ \
		ftp://elib.zib-berlin.de/pub/linpack/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}

pre-build:
	${CP} ${FILESDIR}/makefile.lib ${WRKDIR}/Makefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

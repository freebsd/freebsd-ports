# New ports collection makefile for:    blas
# Version required:     1.0
# Date created:         27 October 1994
# Whom:                 ljo
#
# $FreeBSD$
#

DISTNAME=	blas
PKGNAME=	blas-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/blas/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/blas/ \
		http://www.netlib.org/blas/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes

pre-build:
	${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

# New ports collection makefile for:    lapack
# Version required:     2.0
# Date created:         2 July 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	LAPACK
PKGNAME=	lapack-2.0
CATEGORIES+=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/
DISTFILES=	lapack.tar.gz manpages.tar.gz

MAINTAINER=	jmz@FreeBSD.org

do-install:
	@install -c -o bin -g bin ${WRKSRC}/BLAS/SRC/libblas.* ${PREFIX}/lib
	@install -c -o bin -g bin ${WRKSRC}/SRC/liblapack.* ${PREFIX}/lib
.if !defined(NOMANCOMPRESS)
	@(cd ${WRKDIR}/blas/man/manl; \
	   for i in *.l; do gzip < $$i >${PREFIX}/man/manl/$$i.gz; done)
	@(cd ${WRKDIR}/man/manl; \
	   for i in *.l; do gzip < $$i >${PREFIX}/man/manl/$$i.gz; done)
.endif

.include <bsd.port.mk>

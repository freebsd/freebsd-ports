# New ports collection makefile for:    lapack
# Version required:     2.0
# Date created:         2 July 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.4 1997/07/17 15:12:56 max Exp $
#

DISTNAME=	LAPACK
PKGNAME=	lapack-2.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/
DISTFILES=	lapack.tar.gz manpages.tar.gz

MAINTAINER=	jmz@FreeBSD.org

do-install:
	${INSTALL} -c -o bin -g bin ${WRKSRC}/BLAS/SRC/libblas.* ${PREFIX}/lib
	${INSTALL} -c -o bin -g bin ${WRKSRC}/SRC/liblapack.* ${PREFIX}/lib
	${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOMANCOMPRESS)
	cd ${WRKDIR}/blas/man/manl; \
	   for i in *.l; do ${GZIP_CMD} -9f < $$i >${PREFIX}/man/manl/$$i.gz; done
	cd ${WRKDIR}/man/manl; \
	   for i in *.l; do ${GZIP_CMD} -9f < $$i >${PREFIX}/man/manl/$$i.gz; done
.else
	cd ${WRKDIR}/blas/man/manl; \
	   for i in *.l; do ${CP} $$i ${PREFIX}/man/manl/; done
	cd ${WRKDIR}/man/manl; \
	   for i in *.l; do ${CP} $$i ${PREFIX}/man/manl/; done
.endif

.include <bsd.port.mk>

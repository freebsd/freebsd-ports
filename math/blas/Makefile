# New ports collection makefile for:    blas
# Version required:     ?
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
		ftp://elib.zib-berlin.de/pub/blas/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}

.include <bsd.port.pre.mk>

pre-build:
	${CP} ${FILESDIR}/makefile.lib ${WRKDIR}/Makefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libblas.so.1.0 ${PREFIX}/lib/libblas.so
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:    blas
# Version required:     ?
# Date created:         27 October 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.13 1998/02/02 00:24:51 steve Exp $
#

DISTNAME=	blas
PKGNAME=	blas-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/blas/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	ports@FreeBSD.org

EXTRACT_CMD=	${GUNZIP_CMD} <
EXTRACT_ARGS=
EXTRACT_AFTER_ARGS= | /bin/sh
NO_WRKSUBDIR=	yes

pre-build:
	${CP} ${FILESDIR}/makefile.lib ${WRKDIR}/Makefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

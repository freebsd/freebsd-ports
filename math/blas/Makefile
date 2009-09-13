# New ports collection makefile for:    blas
# Date created:         27 October 1994
# Whom:                 ljo
#
# $FreeBSD$
#

PORTNAME=	blas
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://www.netlib.org/blas/ \
		ftp://ftp.mirrorservice.org/sites/netlib.bell-labs.com/netlib/blas/ \
		ftp://netlib.bell-labs.com/netlib/blas/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Basic Linear Algebra, level 1, 2, and 3

USE_LDCONFIG=	yes
USE_FORTRAN=	yes
WRKSRC=		${WRKDIR}/BLAS

PLIST_FILES=	lib/libblas.a lib/libblas.so lib/libblas.so.2

do-configure:
	@${INSTALL_DATA} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's+@FFLAGS@+${FFLAGS}+g' ${WRKSRC}/Makefile

.include <bsd.port.mk>

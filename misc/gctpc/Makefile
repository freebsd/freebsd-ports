# New ports collection makefile for:	gctpc
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	gctpc
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://edcftp.cr.usgs.gov/pub/software/gctpc/
DISTNAME=	gctpc
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An USGS General Cartographic Transformation Package (GCTP)

WRKSRC=		${WRKDIR}/${PORTNAME}/source

USE_GMAKE=	yes
ALL_TARGET=	libgctpc.so.1

INSTALLS_SHLIB=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libgctpc.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libgctpc.so.1 ${PREFIX}/lib
	${LN} -sf libgctpc.so.1 ${PREFIX}/lib/libgctpc.so
	${MKDIR} ${PREFIX}/include/gctpc
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/gctpc
	${INSTALL_DATA} ${FILESDIR}/*.h ${PREFIX}/include/gctpc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/* ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../README ${DOCSDIR}/README.main
.endif

.include <bsd.port.mk>

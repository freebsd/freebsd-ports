# New ports collection makefile for:    blas
# Version required:     ?
# Date created:         27 October 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.12 1997/07/17 15:12:52 max Exp $
#

DISTNAME=	blas
PKGNAME=	blas-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org

# ${DISTFILES} is automatically created from the directory contents
IGNOREFILES=	${DISTFILES}
EXTRACT_BEFORE_ARGS=	-xvf

post-extract:
	${GUNZIP_CMD} ${WRKSRC}/*.f.gz

pre-build:
	${RM} ${WRKSRC}/.depend
	${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/blas
	${CP} ${WRKSRC}/*.ps.gz $(PREFIX)/share/doc/blas/
.endif
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

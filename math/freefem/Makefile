# New ports collection makefile for:   freefem
# Date created:        20 December 1996
# Whom:                Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	freefem
PORTVERSION=	3.4
CATEGORIES=	math cad
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Gamma/freefem/

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-adapt --with-optimization

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/freefem
	${CP} ${WRKSRC}/doc/freefem.dvi ${PREFIX}/share/doc/freefem
	${CP} ${WRKSRC}/doc/freefem.ps ${PREFIX}/share/doc/freefem
	${CP} ${WRKSRC}/doc/freefem.txt ${PREFIX}/share/doc/freefem
	${GZIP_CMD} ${PREFIX}/share/doc/freefem/freefem.txt
	${RM} -rf ${PREFIX}/share/examples/freefem
	${MV} ${PREFIX}/share/freefem ${PREFIX}/share/examples
.endif

.include <bsd.port.mk>

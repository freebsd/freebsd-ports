# New ports collection makefile for:   freefem
# Version required:    3.4
# Date created:        20 December 1996
# Whom:                Pedro Giffuni
#
# $Id: Makefile,v 1.5 1998/04/01 02:23:51 asami Exp $
#

DISTNAME=	freefem-3.4
CATEGORIES=	math cad
MASTER_SITES=	http://www.asci.fr/~prudhomm/gfem-html/freefem/

MAINTAINER=     giffunip@asme.org

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

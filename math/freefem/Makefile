# New ports collection makefile for:   freefem
# Version required:    3.4
# Date created:        20 December 1996
# Whom:                pgiffuni@FPS.biblos.unal.edu.co
#
# $Id: Makefile,v 1.2 1997/04/17 12:23:45 max Exp $
#

DISTNAME=	freefem-3.4
CATEGORIES=	math cad
MASTER_SITES=	http://www.asci.fr/~prudhomm/gfem-html/freefem/

MAINTAINER=     pgiffuni@FPS.biblos.unal.edu.co

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-adapt --with-optimization

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/freefem
	${MKDIR} ${PREFIX}/share/examples
	${CP} ${WRKSRC}/doc/freefem.dvi ${PREFIX}/share/doc/freefem
	${CP} ${WRKSRC}/doc/freefem.ps ${PREFIX}/share/doc/freefem
	${CP} ${WRKSRC}/doc/freefem.txt ${PREFIX}/share/doc/freefem
	${GZIP_CMD} ${PREFIX}/share/doc/freefem/freefem.txt
	${MV} ${PREFIX}/share/freefem ${PREFIX}/share/examples
.endif

.include <bsd.port.mk>

# New ports collection makefile for:   freefem
# Version required:    3.0
# Date created:        20 December 1996
# Whom:                pgiffuni@FPS.biblos.unal.edu.co
#
# $Id: Makefile,v 1.1.1.1 1997/01/11 11:38:43 asami Exp $
#

DISTNAME=	freefem
PKGNAME=	freefem-3.0
CATEGORIES=	math cad
MASTER_SITES=	ftp://ftp.ann.jussieu.fr/pub/soft/
EXTRACT_SUFX=	.tgz

MAINTAINER=     pgiffuni@FPS.biblos.unal.edu.co

USE_X11=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile.x
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freefem ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/freefem/exampl.pde
	${CP} ${WRKSRC}/freefem.hlp ${PREFIX}/share/doc/freefem
	${GZIP_CMD} ${PREFIX}/share/doc/freefem/freefem.hlp
	${CP} ${WRKSRC}/exampl.pde/* ${PREFIX}/share/doc/freefem/exampl.pde
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	METIS
# Version required:	4.0
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $Id: Makefile,v 1.1.1.1 1998/04/26 03:55:22 mph Exp $
#

DISTNAME=	metis-4.0
CATEGORIES=	math
MASTER_SITES=	http://www.cs.umn.edu/~karypis/metis/metis/files/

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/pmetis	$(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/kmetis	$(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/oemetis	$(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/onmetis	$(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/partnmesh	$(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/partdmesh	$(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/mesh2nodal	$(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/mesh2dual	$(PREFIX)/bin
	$(INSTALL_PROGRAM) $(WRKSRC)/graphchk	$(PREFIX)/bin
	$(INSTALL_DATA) $(WRKSRC)/libmetis.a $(PREFIX)/lib
.if !defined(NOPORTDOCS)
	${MKDIR} $(PREFIX)/share/doc/METIS
	$(INSTALL_DATA) ${WRKSRC}/Doc/manual.ps $(PREFIX)/share/doc/METIS
.endif

.include <bsd.port.mk>

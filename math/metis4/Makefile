# New ports collection makefile for:	METIS
# Version required:	3.0
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $Id$
#

DISTNAME=	metis-3.0
CATEGORIES=	math
MASTER_SITES=	http://www.cs.umn.edu/~karypis/metis/metis/files/

MAINTAINER=	giffunip@asme.org

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

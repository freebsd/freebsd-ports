# New ports collection makefile for:	METIS
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	metis
PORTVERSION=	4.0
CATEGORIES=	math
MASTER_SITES=	http://www-users.cs.umn.edu/~karypis/metis/metis/files/

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
	${MKDIR} $(PREFIX)/include/metis
	$(INSTALL_DATA) $(WRKSRC)/Lib/defs.h    $(PREFIX)/include/metis
	$(INSTALL_DATA) $(WRKSRC)/Lib/macros.h  $(PREFIX)/include/metis
	$(INSTALL_DATA) $(WRKSRC)/Lib/metis.h   $(PREFIX)/include/metis
	$(INSTALL_DATA) $(WRKSRC)/Lib/proto.h   $(PREFIX)/include/metis
	$(INSTALL_DATA) $(WRKSRC)/Lib/rename.h  $(PREFIX)/include/metis
	$(INSTALL_DATA) $(WRKSRC)/Lib/struct.h  $(PREFIX)/include/metis
.if !defined(NOPORTDOCS)
	${MKDIR} $(PREFIX)/share/doc/METIS
	$(INSTALL_DATA) ${WRKSRC}/Doc/manual.ps $(PREFIX)/share/doc/METIS
.endif

.include <bsd.port.mk>

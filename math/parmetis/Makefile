# New ports collection makefile for:	ParMETIS
# Date created:         19 May 99
# Whom:                 Eoin Lawless (eoin@maths.tcd.ie)
#
# $FreeBSD$
#

PORTNAME=	ParMetis
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	math parallel
MASTER_SITES=	http://www-users.cs.umn.edu/~karypis/metis/parmetis/files/

MAINTAINER=	eoin@maths.tcd.ie
COMMENT=	A package for parallel (mpi) unstructured graph partitioning

RUN_DEPENDS=	$(PREFIX)/mpich/bin/mpirun:${PORTSDIR}/net/mpich
BUILD_DEPENDS=	$(PREFIX)/mpich/bin/mpicc:${PORTSDIR}/net/mpich

ALL_TARGET=

do-install:
	${MKDIR} $(PREFIX)/lib/parmetis
	$(INSTALL_DATA) $(WRKSRC)/libmetis.a $(PREFIX)/lib/parmetis
	$(INSTALL_DATA) $(WRKSRC)/libparmetis.a $(PREFIX)/lib/parmetis
	${MKDIR} $(PREFIX)/include/parmetis
	$(INSTALL_DATA) $(WRKSRC)/parmetis.h    $(PREFIX)/include/parmetis
.if !defined(NOPORTDOCS)
	${MKDIR} $(PREFIX)/share/doc/ParMETIS
	$(INSTALL_DATA) ${WRKSRC}/Manual/manual.ps $(PREFIX)/share/doc/ParMETIS
	$(INSTALL_DATA) ${WRKSRC}/Manual/manual.pdf $(PREFIX)/share/doc/ParMETIS
.endif

.include <bsd.port.mk>

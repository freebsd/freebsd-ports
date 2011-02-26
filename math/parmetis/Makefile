# New ports collection makefile for:	ParMETIS
# Date created:         19 May 99
# Whom:                 Eoin Lawless (eoin@maths.tcd.ie)
#
# $FreeBSD$
#

PORTNAME=	ParMetis
PORTVERSION=	3.1
PORTREVISION=	6
CATEGORIES=	math parallel
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/parmetis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A package for parallel (mpi) unstructured graph partitioning

RUN_DEPENDS=	${LOCALBASE}/bin/mpirun:${PORTSDIR}/net/mpich2
BUILD_DEPENDS=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2

ALL_TARGET=

do-install:
	@${MKDIR} $(PREFIX)/lib/parmetis
	$(INSTALL_DATA) $(WRKSRC)/libmetis.a $(PREFIX)/lib/parmetis
	$(INSTALL_DATA) $(WRKSRC)/libparmetis.a $(PREFIX)/lib/parmetis
	@${MKDIR} $(PREFIX)/include/parmetis
	$(INSTALL_DATA) $(WRKSRC)/parmetis.h    $(PREFIX)/include/parmetis
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	$(INSTALL_DATA) ${WRKSRC}/Manual/manual.ps ${DOCSDIR}
	$(INSTALL_DATA) ${WRKSRC}/Manual/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>

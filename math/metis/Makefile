# New ports collection makefile for:	METIS
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	metis
PORTVERSION=	4.0
CATEGORIES=	math
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/	\
		http://www-users.cs.umn.edu/~karypis/metis/metis/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A package for unstructured graph partitioning

CONFLICTS=	metis-edf-[0-9]*

ALL_TARGET=

PROGRAMS=	graphchk kmetis mesh2dual mesh2nodal	\
		oemetis onmetis partnmesh partdmesh pmetis

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
post-configure:
	@${REINPLACE_CMD} -e 's+COPTIONS =+COPTIONS = -fPIC+;'	\
		${WRKSRC}/Makefile.in
.endif

do-install:
.for p in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/include/metis
	${INSTALL_DATA} ${WRKSRC}/Lib/*.h    ${PREFIX}/include/metis
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${PREFIX}/lib
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/manual.ps ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

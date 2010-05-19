# New ports collection makefile for:	METIS
# Date created:         26 Oct 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	metis
PORTVERSION=	4.0
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/	\
		http://www-users.cs.umn.edu/~karypis/metis/metis/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A package for unstructured graph partitioning

CONFLICTS=	metis-edf-[0-9]*

ALL_TARGET=
USE_LDCONFIG=	yes

PROGRAMS=	graphchk kmetis mesh2dual mesh2nodal	\
		oemetis onmetis partnmesh partdmesh pmetis

.include <bsd.port.pre.mk>
.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-patch:
	${MKDIR} ${WRKSRC}_SHARED ; ${CP} -r ${WRKSRC}/* ${WRKSRC}_SHARED

do-build:
	cd ${WRKSRC} ; ${MAKE}
	cd ${WRKSRC}_SHARED ; ${SETENV} CFLAGS="${CFLAGS} ${PICFLAG}" ${MAKE} ; ld -Bshareable -o libmetis.so.1 -x -soname libmetis.so.1 --whole-archive libmetis.a

do-install:
.for p in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/include/metis
	${INSTALL_DATA} ${WRKSRC}/Lib/*.h    ${PREFIX}/include/metis
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}_SHARED/libmetis.so.1 ${PREFIX}/lib
	${LN} -sf libmetis.so.1 ${PREFIX}/lib/libmetis.so

.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/manual.ps ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

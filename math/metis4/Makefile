# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	metis4
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://glaros.dtc.umn.edu/gkhome/fetch/sw/metis/OLD/
DISTNAME=	metis-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A package for unstructured graph partitioning

LICENSE=	METIS
LICENSE_NAME=	University of Minnesota METIS License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept

CONFLICTS=	metis-5* metis-edf-[0-9]*

USE_LDCONFIG=	yes

PORTSCOUT=	limit:4.*
PROGRAMS=	graphchk kmetis mesh2dual mesh2nodal	\
		oemetis onmetis partnmesh partdmesh pmetis

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

post-patch:
	${CP} -R ${WRKSRC} ${WRKSRC}_SHARED

do-build:
	@cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} \
	COPTIONS="${CFLAGS}" LDOPTIONS="${LDFLAGS}" \
	${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS}
	@cd ${WRKSRC}_SHARED ; ${SETENV} ${MAKE_ENV} \
	COPTIONS="${CFLAGS} ${PICFLAG}" LDOPTIONS="${LDFLAGS} ${PICFLAG}" \
	${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} ; \
	${LD} -Bshareable -o libmetis.so.1 -x -soname libmetis.so.1 \
	--whole-archive libmetis.a --no-whole-archive

check regression-test test: build
	cd ${WRKSRC}/Graphs ; ./mtest 4elt.graph

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin
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

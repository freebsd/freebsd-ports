# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	parmgridgen
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	math science
MASTER_SITES=	http://www.mgnet.org/mgnet/Codes/parmgridgen/ \
		http://www-users.cs.umn.edu/~moulitsa/download/ \
		http://www.stasyan.com/devel/distfiles/
DISTNAME=	ParMGridGen-${PORTVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	Library for obtaining a sequence of successive coarse grids

ALL_TARGET=	parallel

LIB_DEPENDS+=	mpi.1:${PORTSDIR}/net/openmpi
USES=		gmake
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
post-patch:
		@${REINPLACE_CMD} 's|make|$$(MAKE)|g' ${WRKSRC}/Makefile
#respect CFLAGS
.		for f in IMlib Lib Programs
		    @${REINPLACE_CMD} 's|CFLAGS =|CFLAGS+=|g' ${WRKSRC}/MGridGen/${f}/Makefile
.		endfor
.		for f in IMParMetis-2.0 ParLib Programs
		    @${REINPLACE_CMD} 's|CFLAGS =|CFLAGS+=|g' ${WRKSRC}/ParMGridGen/${f}/Makefile
.		endfor
do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/mgridgen ${PREFIX}/bin/mgridgen
		${INSTALL_PROGRAM} ${WRKSRC}/parmgridgen ${PREFIX}/bin/parmgridgen
		${INSTALL_PROGRAM} ${WRKSRC}/libmgrid.a ${PREFIX}/lib/libmgrid.a
		${INSTALL_PROGRAM} ${WRKSRC}/libparmgrid.a ${PREFIX}/lib/libparmgrid.a
		${INSTALL_DATA} ${WRKSRC}/mgridgen.h ${PREFIX}/include/mgridgen.h
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>

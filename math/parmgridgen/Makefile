# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	parmgridgen
PORTVERSION=	1.0
PORTREVISION=	13
CATEGORIES=	math science
MASTER_SITES=	http://www.mgnet.org/mgnet/Codes/parmgridgen/ \
		http://www-users.cs.umn.edu/~moulitsa/download/ \
		http://www.stasyan.com/devel/distfiles/
DISTNAME=	ParMGridGen-${PORTVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	Library for obtaining a sequence of successive coarse grids

LIB_DEPENDS=	libmpi.so:net/openmpi

ALL_TARGET=	parallel
USES=		gmake
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|make|$$(MAKE)|g' ${WRKSRC}/Makefile
#respect CFLAGS
.	for f in IMlib Lib Programs
	    @${REINPLACE_CMD} 's|CFLAGS =|CFLAGS+=|g' ${WRKSRC}/MGridGen/${f}/Makefile
.	endfor
.	for f in IMParMetis-2.0 ParLib Programs
	    @${REINPLACE_CMD} 's|CFLAGS =|CFLAGS+=|g' ${WRKSRC}/ParMGridGen/${f}/Makefile
.	endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mgridgen ${STAGEDIR}${PREFIX}/bin/mgridgen
	${INSTALL_PROGRAM} ${WRKSRC}/parmgridgen ${STAGEDIR}${PREFIX}/bin/parmgridgen
	${INSTALL_DATA} ${WRKSRC}/libmgrid.a ${STAGEDIR}${PREFIX}/lib/libmgrid.a
	${INSTALL_DATA} ${WRKSRC}/libparmgrid.a ${STAGEDIR}${PREFIX}/lib/libparmgrid.a
	${INSTALL_DATA} ${WRKSRC}/mgridgen.h ${STAGEDIR}${PREFIX}/include/mgridgen.h

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>

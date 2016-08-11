# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	gctpc
PORTVERSION=	2.0
CATEGORIES=	misc geography
MASTER_SITES=	http://www.nco.ncep.noaa.gov/pmb/codes/nwprod/util/sorc/wgrib2.cd/grib2/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	USGS General Cartographic Transformation Package (GCTP)

WRKSRC=		${WRKDIR}/${PORTNAME}/source

USES=		gmake tar:Z
ALL_TARGET=	libgctpc.so.1
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} ${FILESDIR} -name "*.h" -not -name "patch-*" -exec \
		${INSTALL_DATA} {} ${WRKSRC} \;

do-install:
	${INSTALL_DATA} ${WRKSRC}/libgctpc.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libgctpc.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libgctpc.so.1 ${STAGEDIR}${PREFIX}/lib/libgctpc.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/gctpc
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/gctpc

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}/README.main

.include <bsd.port.mk>

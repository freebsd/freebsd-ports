# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	gctpc
PORTVERSION=	2.0
CATEGORIES=	misc geography
MASTER_SITES=	http://edcftp.cr.usgs.gov/pub/software/gctpc/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	USGS General Cartographic Transformation Package (GCTP)

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}/source

USES=		gmake tar:Z
ALL_TARGET=	libgctpc.so.1
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

post-extract:
	@${FIND} ${FILESDIR} -name "*.h" -not -name "patch-*" -exec \
		${INSTALL_DATA} {} ${WRKSRC} \;

do-install:
	${INSTALL_DATA} ${WRKSRC}/libgctpc.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libgctpc.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libgctpc.so.1 ${STAGEDIR}${PREFIX}/lib/libgctpc.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/gctpc
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/gctpc
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}/README.main

.include <bsd.port.mk>

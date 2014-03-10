# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	cdf3
PORTVERSION=	3.3.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_LOCAL}	\
		ftp://cdaweb.gsfc.nasa.gov/pub/cdf/dist/cdf${VER}/unix/
MASTER_SITE_SUBDIR=	thierry/${PORTNAME}
DISTNAME=	cdf${VER}-dist-cdf
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Device independent view of the CDF data model

MAKE_FLAGS=	INSTALLDIR=${STAGEDIR}${PREFIX} OS=${OPSYS:L} ENV=gnu      \
		FORTRAN=yes FC_freebsd=${F77}
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

VER=		${PORTVERSION:S/.//:S/./_/}

USES=		fortran

WRKSRC=		${WRKDIR}/cdf${VER}-dist
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

DEFS=		B C K
PORTDOCS=	CDF_copyright.txt CHANGES.txt Release.notes Welcome.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

pre-configure:
.for def in ${DEFS}
	${REINPLACE_CMD} -e 's|<path>|${PREFIX}|'		\
		 ${WRKSRC}/src/definitions/definitions.${def}
.endfor

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libcdf.so ${STAGEDIR}${PREFIX}/lib/libcdf.so.0
	${LN} -sf libcdf.so.0 ${STAGEDIR}${PREFIX}/lib/libcdf.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

regression-test:
	(cd ${BUILD_WRKSRC} ;	\
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

.include <bsd.port.post.mk>

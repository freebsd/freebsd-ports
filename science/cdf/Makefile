# New ports collection makefile for:	cdf
# Date created:		26 January 2006
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	cdf3
PORTVERSION=	3.1
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	ftp://nssdcftp.gsfc.nasa.gov/standards/cdf/dist/cdf${VER}/unix/	\
		http://windsor.gsfc.nasa.gov/standards/cdf/dist/cdf${VER}/unix/
DISTNAME=	cdf${VER}-dist-cdf
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Device independent view of the CDF data model

MAKE_FLAGS=	INSTALLDIR=${PREFIX} OS=${OPSYS:L} ENV=gnu	\
		FORTRAN=yes F77=${F77}
INSTALLS_SHLIB=	yes

VER=		${PORTVERSION:S/.//}

F77?=		f77

WRKSRC=		${WRKDIR}/cdf${VER}-dist
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

DEFS=		B C K
PORTDOCS=	CDF_copyright.txt CHANGES.txt Release.notes Welcome.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
.endif

pre-configure:
.for def in ${DEFS}
	${REINPLACE_CMD} -e 's|<path>|${PREFIX}|'		\
		 ${WRKSRC}/src/definitions/definitions.${def}
.endfor

post-install:
	${MV} ${PREFIX}/lib/libcdf.so ${PREFIX}/lib/libcdf.so.0
	${LN} -sf ${PREFIX}/lib/libcdf.so.0 ${PREFIX}/lib/libcdf.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.if defined(MAINTAINER_MODE)
regression-test:	build
	(cd ${BUILD_WRKSRC} ;	\
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.endif

.include <bsd.port.post.mk>

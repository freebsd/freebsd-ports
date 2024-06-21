PORTNAME=	SLICOT
PORTVERSION=	5.9
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Fortran subroutines library for systems and control
WWW=		https://slicot.org/

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_PROJECT=	SLICOT-Reference

USES=		blaslapack:openblas fortran

BINARY_ALIAS=	gfortran=${FC}
FFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKEFILE=	makefile_Unix
MAKE_ENV=	FORTRAN=${FC} OPTS="${FFLAGS} -fPIC" LOADER=${FC}	\
		LOADOPTS="${WRKSRC}/slicot.a ${WRKSRC}/lpkaux.a ${LDFLAGS} ${BLASLIB} ${LAPACKLIB}"
MAKE_JOBS_UNSAFE=yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
PORTDOCS=	*

post-build:
	(cd ${WRKSRC} &&	\
	${CP} slicot.a libslicot.a &&	\
	${FC} ${LDFLAGS} -shared -Wl,-soname=libslicot.so.0	\
		-o libslicot.so.0.0 src/*.o ${BLASLIB} ${LAPACKLIB} &&	\
	${LN} -sf libslicot.so.0.0 libslicot.so.0 &&	\
	${LN} -sf libslicot.so.0.0 libslicot.so)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libslicot.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libslicot.so.0.0 ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libslicot.so.0.0	\
		${STAGEDIR}${PREFIX}/lib/libslicot.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libslicot.so.0.0	\
		${STAGEDIR}${PREFIX}/lib/libslicot.so.0

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README.md libindex.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${FIND} ${WRKSRC}/examples -name "T*" -a ! -name "*\.*" |	\
		${XARGS} ${STRIP_CMD}
	${RM} ${WRKSRC}/examples/*.o ${WRKSRC}/../examples/makefile.bak	\
		${WRKSRC}/examples/makefile.orig
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

PORTNAME=	SLICOT
PORTVERSION=	5.8
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Fortran subroutines library for systems and control
WWW=		http://slicot.org/

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_PROJECT=	SLICOT-Reference

USES=		blaslapack:openblas fortran

WRKSRC_SUBDIR=	src
PATCH_WRKSRC=	${WRKDIR}/${GH_PROJECT}-${PORTVERSION}
MAKEFILE=	makefile
MAKE_ENV=	FORTRAN=${FC} OPTS="${FFLAGS} -fPIC" LOADER=${FC}	\
		LOADOPTS="../src/libslicot.a ${FFLAGS} ${BLASLIB} ${LAPACKLIB}"
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
PORTDOCS=	*

post-build:
	(cd ${WRKSRC} &&	\
	${AR} ${ARFLAGS} libslicot.a *.o &&	\
	${FC} ${LDFLAGS} -shared -Wl,-soname=libslicot.so.0	\
		-o libslicot.so.0.0 *.o ${BLASLIB} ${LAPACKLIB} &&	\
	${LN} -sf libslicot.so.0.0 libslicot.so.0 &&	\
	${LN} -sf libslicot.so.0.0 libslicot.so)

pre-configure-EXAMPLES-on:
	${REINPLACE_CMD} -e 's|\\src\\|/src/|;s|\.obj|.o|g;s|\-exe:|-o |;s|exe;  T|exe;  ./T|'	\
		${WRKSRC}/../examples/${MAKEFILE}

post-build-EXAMPLES-on:
	(cd ${WRKSRC}/../examples && ${DO_MAKE_BUILD} ${ALL_TARGET})

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
	${INSTALL_DATA} ${WRKSRC}/../${f} ${STAGEDIR}${DOCSDIR}
.endfor
	cd ${WRKSRC}/.. && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${FIND} ${WRKSRC}/../examples -name "T*" -a ! -name "*\.*" |	\
		${XARGS} ${STRIP_CMD}
	${RM} ${WRKSRC}/../examples/*.o ${WRKSRC}/../examples/makefile.bak	\
		${WRKSRC}/../examples/makefile.orig
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/../examples &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

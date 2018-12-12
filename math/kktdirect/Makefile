# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	kktdirect
PORTVERSION=	0.5
PORTREVISION=	10
CATEGORIES=	math
MASTER_SITES=	http://www.cs.ubc.ca/~rbridson/download/ LOCAL/bf
DISTNAME=	KKTDirect${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Direct solver package for saddle-point (KKT) matrices

USES=		fortran
USE_LDCONFIG=	yes

CFLAGS+=	-DUSE_FORTRAN_BLAS -DUSE_FORTRAN_LAPACK
LDFLAGS+=	-L${LOCALBASE}/lib ${LAPACK} ${BLAS} -lm
PLIST_FILES=	include/kktdirect.h lib/libkktdirect.a lib/libkktdirect_pic.a \
		lib/libkktdirect.so lib/libkktdirect.so.0

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

.if exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == reference
LIB_DEPENDS+=	libblas.so:math/blas
LIB_DEPENDS+=	liblapack.so:math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	libgoto2p.so:math/gotoblas
BLAS=			-lgoto2p
LAPACK=		-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	libatlas.so:math/atlas
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
.endif

PORTDOCS=	kktdirect.pdf
PORTEXAMPLES=	kktsolve.cpp

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's@CPP@CXX@g' \
		-e '\@^(CC|CXX) =@s@^@#@' \
		-e 's@^(C|CXX|LD)(FLAGS )(=)(.*)@\1\2+\3 $${PICFLAG}@' \
		-e 's@ar r@${AR} r@' \
		-e 's@ranlib@${RANLIB}@' \
			${WRKSRC}/Makefile

pre-build:
	${CP} -a ${WRKSRC} ${WRKSRC}_shared

do-build:
	@cd ${WRKSRC}_shared && ${DO_MAKE_BUILD} PICFLAG="${PICFLAG}" libkktdirect.a && \
		${CXX} ${CXXFLAGS} -shared -Wl,-soname,libkktdirect.so.0 \
		-o ${WRKDIR}/libkktdirect.so.0 -Wl,--whole-archive libkktdirect.a \
		-Wl,--no-whole-archive -Wl,--as-needed ${LDFLAGS} && \
		${CP} -af libkktdirect.a ${WRKDIR}/libkktdirect_pic.a
	@cd ${WRKSRC} && ${DO_MAKE_BUILD} PICFLAG="" libkktdirect.a && \
		${CP} -af libkktdirect.a ${WRKDIR}

do-test:
	@cd ${WRKSRC} && ${DO_MAKE_BUILD} PICFLAG="" stokes && ./stokes 3

do-install:
	${INSTALL_DATA} ${WRKSRC}/kktdirect.h ${STAGEDIR}${PREFIX}/include
	cd ${WRKDIR} && ${INSTALL_DATA} libkktdirect.a libkktdirect_pic.a \
		${STAGEDIR}${PREFIX}/lib
	cd ${WRKDIR} && ${INSTALL_LIB} libkktdirect.so.0 ${STAGEDIR}${PREFIX}/lib
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf libkktdirect.so.0 libkktdirect.so

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>

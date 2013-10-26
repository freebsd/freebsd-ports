# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	kktdirect
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.cs.ubc.ca/~rbridson/download/ LOCAL/bf
DISTNAME=	KKTDirect${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Direct solver package for saddle-point (KKT) matrices

USE_FORTRAN=	yes
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-DUSE_FORTRAN_BLAS -DUSE_FORTRAN_LAPACK
LDFLAGS+=	-L${LOCALBASE}/lib ${LAPACK} ${BLAS} -lm
PLIST_FILES=	include/kktdirect.h lib/libkktdirect.a lib/libkktdirect_pic.a \
		lib/libkktdirect.so lib/libkktdirect.so.0

NO_STAGE=	yes
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
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK =	-llapack
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	goto2:${PORTSDIR}/math/gotoblas
BLAS =		-lgoto2p
LAPACK =	-lgoto2p
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
LAPACK =	-lalapack -lptcblas
.endif

.ifndef(NOPORTDOCS)
PORTDOCS=	kktdirect.pdf
.endif

.ifndef(NOPORTEXAMPLES)
PORTEXAMPLES=	kktsolve.cpp
.endif

post-patch:
	@${REINPLACE_CMD} -E \
	-e 's@CPP@CXX@g' \
	-e '\@^(CC|CXX) =@s@^@#@' \
	-e 's@^(C|CXX|LD)(FLAGS )(=)(.*)@\1\2+\3 $${PICFLAG}@' \
	-e 's@ar r@${AR} r@' \
	-e 's@ranlib@${RANLIB}@' \
		${WRKSRC}/Makefile

do-build: build-dynamic build-static

.ORDER: build-dynamic build-static

build-dynamic: patch
	@cd ${WRKSRC};  ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} PICFLAG="${PICFLAG}" clean libkktdirect.a ; \
	${CXX} ${CXXFLAGS} -shared -Wl,-x -Wl,-soname,libkktdirect.so.0 \
	-o ${WRKDIR}/libkktdirect.so.0 -Wl,--whole-archive libkktdirect.a \
	-Wl,--no-whole-archive -Wl,--as-needed ${LDFLAGS} ; \
	${CP} -af libkktdirect.a ${WRKDIR}/libkktdirect_pic.a

build-static: patch
	@cd ${WRKSRC};  ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} PICFLAG="" clean libkktdirect.a ; \
	${CP} -af libkktdirect.a ${WRKDIR}

check regression-test test: build
	@cd ${WRKSRC};  ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} PICFLAG="" stokes ; \
	./stokes 3

do-install:
	@${INSTALL_DATA} ${WRKSRC}/kktdirect.h ${PREFIX}/include
	@cd ${WRKDIR}; ${INSTALL_DATA} libkktdirect.a libkktdirect_pic.a \
	libkktdirect.so.0 ${PREFIX}/lib
	@${LN} -sf libkktdirect.so.0 ${PREFIX}/lib/libkktdirect.so
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>

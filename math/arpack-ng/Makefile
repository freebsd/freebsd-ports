# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arpack-ng
PORTVERSION=	3.1.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://forge.scilab.org/index.php/p/arpack-ng/downloads/get/ \
		LOCAL/bf
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Revised Argand library for solving large-scale eigenvalue problems

LICENSE=	BSD

USES=		fortran
USE_LDCONFIG=	yes

CONFLICTS=	arpack-[0-9]*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS =	--disable-mpi --with-blas="${BLAS}" \
			--with-lapack="${LAPACK}"
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/bug_1323 \
		bin/dnsimp \
		lib/libarpack.a \
		lib/libarpack.la \
		lib/libarpack.so \
		lib/libarpack.so.2 \
		libdata/pkgconfig/arpack.pc

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
.endif

WITH_BLAS?=	blas

.if ${WITH_BLAS} == "gotoblas"
BLAS=		-lgoto2p
LAPACK =	-lgoto2p
LIB_DEPENDS+=	libgoto2p.so:${PORTSDIR}/math/gotoblas
.elif ${WITH_BLAS} == "atlas"
BLAS=		-lptf77blas
LAPACK =	-lalapack -lptcblas
LIB_DEPENDS+=	libptf77blas.so:${PORTSDIR}/math/atlas
.elif ${WITH_BLAS} == "blas"
BLAS=		-lblas
LAPACK =	-llapack
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas \
		liblapack.so:${PORTSDIR}/math/lapack
.else
IGNORE =	unknown value of WITH_BLAS: ${WITH_BLAS}
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|\(libdir\)(/pkgconfig)|(prefix)/libdata\1|' \
	${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/BLAS_LIBS.*LAPACK_LIBS/ \
	{s/LAPACK_LIBS/BLAS_LIBS/;s/BLAS_LIBS/LAPACK_LIBS/;}' \
	${WRKSRC}/Makefile.in \
	${WRKSRC}/arpack.pc.in \
	${WRKSRC}/TESTS/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/EXAMPLES && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

check regression-test test: build
	@cd ${WRKSRC}/TESTS ; \
	${SETENV} LD_LIBRARY_PATH="${WRKSRC}/.libs:/lib:${LOCALBASE}/lib" \
	./dnsimp

.include <bsd.port.post.mk>

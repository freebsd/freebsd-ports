# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arpack-ng
PORTVERSION=	3.1.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://forge.scilab.org/index.php/p/arpack-ng/downloads/get/ \
		LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Revised Argand library for solving large-scale eigenvalue problems

LICENSE=	BSD

USE_FORTRAN=	yes
USE_LDCONFIG=	yes

CONFLICTS=	arpack-[0-9]*

GNU_CONFIGURE=	yes

CONFIGURE_ARGS =	--disable-mpi --with-blas="${BLAS}" \
			--with-lapack="${LAPACK}"
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/dnsimp \
		lib/libarpack.a \
		lib/libarpack.la \
		lib/libarpack.so \
		lib/libarpack.so.2 \
		libdata/pkgconfig/arpack.pc

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
LIB_DEPENDS+=	goto2p:${PORTSDIR}/math/gotoblas
.elif ${WITH_BLAS} == "atlas"
BLAS=		-lptf77blas
LAPACK =	-lalapack -lptcblas
LIB_DEPENDS+=	ptf77blas:${PORTSDIR}/math/atlas
.elif ${WITH_BLAS} == "blas"
BLAS=		-lblas
LAPACK =	-llapack
LIB_DEPENDS+=	blas:${PORTSDIR}/math/blas \
		lapack:${PORTSDIR}/math/lapack
.else
IGNORE =	unknown value of WITH_BLAS: ${WITH_BLAS}
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|\(libdir\)(/pkgconfig)|(prefix)/libdata\1|' \
	${WRKSRC}/Makefile.in

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

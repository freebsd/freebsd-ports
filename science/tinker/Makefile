# Created by: Glenn Johnson
# $FreeBSD$

PORTNAME=	tinker
DISTVERSION=	8.4.4
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://dasher.wustl.edu/tinker/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General purpose molecular modelling package

LICENSE=	TINKER
LICENSE_NAME=	TINKER license agreement
LICENSE_FILE=	${WRKSRC}/doc/license.pdf
LICENSE_PERMS=	auto-accept # internal academic purposes only, no commercial use

OPTIONS_DEFINE=	OPTIMIZED_FFLAGS DOCS EXAMPLES
OPTIMIZED_FFLAGS_DESC=	compilation optimizations

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/source
INSTALL_WRKSRC=	${WRKSRC}/source

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		fortran gmake
MAKE_ENV=	HAVE_G2C=yes
MAKE_ARGS=	RANLIB=ranlib BINDIR=${STAGEDIR}${PREFIX}/bin
MAKEFILE=	${WRKSRC}/make/Makefile
EXTRACT_AFTER_ARGS=--exclude fftw --exclude windows --exclude macosx

SUB_FILES=	pkg-message

BINARY_ALIAS=	gfortran=gfortran${GCC_DEFAULT}

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_FFLAGS}
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
.if (${ARCH} == "i386")
FFLAGS+=	-mfancy-math-387 -malign-double
.endif # i386
.endif

post-extract:
	@${RM} ${BUILD_WRKSRC}/*.c
	@${RM} ${WRKSRC}/other/eopbend.orig

post-patch:
	@${REINPLACE_CMD} -i '' 's|\.\./bin/|${STAGEDIR}${PREFIX}/bin/|' ${BUILD_WRKSRC}/../bench/bench*.run

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/params
	cd ${WRKSRC}/params && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}/params
	@${MKDIR} ${STAGEDIR}${DATADIR}/test
	cd ${WRKSRC}/test && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}/test

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} 0README *.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${INSTALL_DATA} \
		0README *.make *.dyn *.int *.frac *.key *.seq *.pdb *.xyz \
		${STAGEDIR}${EXAMPLESDIR}

benchmarks: stage
.for n in 1 2 3 4 5 6 7 8 9
	@cd ${BUILD_WRKSRC}/../bench && ./bench${n}.run
.endfor

.include <bsd.port.mk>

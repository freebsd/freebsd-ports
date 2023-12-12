PORTNAME=	ukrmol+
DISTVERSION=	3.2
PORTREVISION=	4
CATEGORIES=	science # chemistry, physics
MASTER_SITES=	https://zenodo.org/record/5799134/files/:out \
		https://zenodo.org/record/5799110/files/:in # the project is a sum of two projects, "in" and "out"
DISTFILES=	ukrmol-out-${DISTVERSION}${EXTRACT_SUFX}:out \
		ukrmol-in-${DISTVERSION}${EXTRACT_SUFX}:in

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code to compute electron and positron scattering from molecules
WWW=		https://zenodo.org/record/5799134 #.Yo1lCknMKV4

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	fails to build: Cannot open module file 'ieee_arithmetic.mod' for reading

LIB_DEPENDS=	libGBTO.so:science/gbtolib \
		libopenblas.so:math/openblas

USES=		cmake:testing fortran python:test

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	WITH_MPI BUILD_DOC WITH_GIT BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING
CMAKE_ARGS=	-DFREEBSD_DOCSDIR=${DOCSDIR} \
		-DFREEBSD_PYTHON_VER=${PYTHON_VER}
CMAKE_ARGS+=	-DUKRMOL_OUT_DIR=${WRKSRC_OUT} # the "out" project is built and installed from the "in" project

FFLAGS+=	-I${LOCALBASE}/include/gbtolib \
		-fdefault-integer-8
LDFLAGS+=	-lGBTO

WRKSRC_OUT=	${WRKDIR}/ukrmol-out-${PORTVERSION}
WRKSRC_IN=	${WRKDIR}/ukrmol-in-${PORTVERSION}
WRKSRC=		${WRKSRC_IN}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-extract:
	@cd ${WRKDIR} && ${LN} -s ukrmol-out-${PORTVERSION} ukrmol-out

post-install:
	# remove GBTOlib that it bundles
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} -r bin/basis_read bin/print_orbital_table bin/scatci_integrals include/gbtolib lib/libGBTO.so
	# remove an empty directory
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/den

.include <bsd.port.mk>

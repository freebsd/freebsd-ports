# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	superlu
PORTVERSION=	5.2.0
CATEGORIES=	math
MASTER_SITES=	http://crd-legacy.lbl.gov/~xiaoye/SuperLU/ \
		http://crd-legacy.lbl.gov/~xiaoye/:doc
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of routines for performing sparse factorization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake:outsource fortran

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/SuperLU_${PORTVERSION}
PLIST_SUB=	P_VERSION="${P_VERSION}" P_VER="${P_VER}"

CMAKE_ARGS=	-DUSE_XSDK_DEFAULTS:BOOL=ON \
		-Denable_examples:BOOL=OFF

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS TEST
OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS GOTOBLAS REFERENCE
OPTIONS_DEFAULT=	REFERENCE

ATLAS_USES=		blaslapack:atlas
ATLAS_CMAKE_ARGS=	-DBLA_VENDOR:STRING="ATLAS"
DOCS_DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${SLU_DOCS:S/$/:doc/}
DOCS_EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
GOTOBLAS_DESC=		GotoBLAS blas implementation
GOTOBLAS_USES=		blaslapack:gotoblas
GOTOBLAS_CMAKE_ARGS=	-DBLA_VENDOR:STRING="Goto"
REFERENCE_DESC=		Reference blas implementation
REFERENCE_USES=		blaslapack
REFERENCE_CMAKE_ARGS=	-DBLA_VENDOR:STRING="Generic"
TEST_CMAKE_ARGS=	-Denable_tests:BOOL=ON

P_VERSION=	5.1.1
P_VER=		${P_VERSION:C/^([[:alnum:]]+).*/\1/}
SLU_DOCS=	SLU_general.ps.gz simax-29176.pdf

post-patch:
	@${REINPLACE_CMD} -e \
		'/CMAKE_C_FLAGS_RELEASE/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		'/FFLAGS/s|FATAL_ERROR|WARNING|' ${WRKSRC}/cmake/XSDKDefaults.cmake
	@${REINPLACE_CMD} -e \
		's|\(/include\)$$|\1/superlu|' ${WRKSRC}/SRC/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${SLU_DOCS} \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/DOC && ${COPYTREE_SHARE} "html ug.pdf" \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

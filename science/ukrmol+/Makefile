PORTNAME=	ukrmol+
DISTVERSION=	3.2
CATEGORIES=	science # chemistry, physics
MASTER_SITES=	https://zenodo.org/record/5799134/files/
DISTNAME=	ukrmol-out-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code to compute electron and positron scattering from molecules

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libGBTO.so:science/gbtolib \
		libgsl.so:math/gsl \
		libopenblas.so:math/openblas

USES=		cmake:testing fortran localbase python:test

CMAKE_ON=	BUILD_SHARED_LIBS WITH_GSL
CMAKE_OFF=	BUILD_DOC WITH_GIT BUILD_TESTING
CMAKE_TESTING_ON=	BUILD_TESTING # test executables aren't built, see https://gitlab.com/Uk-amor/UKRMol/UKRmol-out/-/issues/40
CMAKE_ARGS=	-DFREEBSD_DOCSDIR=${DOCSDIR} \
		-DFREEBSD_PYTHON_VER=${PYTHON_VER}

FFLAGS+=	-I${LOCALBASE}/include/gbtolib
LDFLAGS+=	-lGBTO

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>

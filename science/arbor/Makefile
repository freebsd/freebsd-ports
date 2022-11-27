PORTNAME=	arbor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-compartment neural network simulation library
WWW=		https://arbor-sim.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		libfmt>0:devel/libfmt \
		nlohmann-json>0:devel/nlohmann-json \
		random123>0:devel/random123 \
		${PYTHON_PKGNAMEPREFIX}svgwrite>0:graphics/py-svgwrite@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}svgwrite>0:graphics/py-svgwrite@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	arbor-sim

SHEBANG_FILES=	scripts/arbor-build-catalogue

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}

post-install:
	@${RMDIR} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

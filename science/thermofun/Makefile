PORTNAME=	thermofun
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.3
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code for calculating thermodynamic properties of materials
WWW=		https://thermohub.org/thermofun/thermofun/ \
		https://github.com/thermohub/thermofun/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		spdlog>0:devel/spdlog
LIB_DEPENDS=	libChemicalFun.so:science/chemicalfun

USES=		cmake compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	thermohub

CMAKE_OFF=	TFUN_USE_AUTODIFF # TODO add port for autodiff library

TEST_WRKSRC=	${WRKSRC}

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_USE=		PYTHON=pytest
PYTHON_CMAKE_BOOL=	TFUN_BUILD_PYTHON
PYTHON_BUILD_DEPENDS=	pybind11>0:devel/pybind11

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib:${STAGEDIR}${LOCALBASE}/lib
TEST_ARGS=	--disable-plugin-autoload

# tests as of 0.7.3: 59 passed, 53 skipped in 0.66s

.include <bsd.port.mk>

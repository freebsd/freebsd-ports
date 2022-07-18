PORTNAME=	thermofun
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code for calculating thermodynamic properties of materials

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		spdlog>0:devel/spdlog
LIB_DEPENDS=	libChemicalFun.so:science/chemicalfun

USES=		cmake compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	thermohub

CXXFLAGS+=	-DSPDLOG_FMT_EXTERNAL # see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=258073#c3

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_USE=		PYTHON=pytest # 2 tests fail, see https://github.com/thermohub/thermofun/issues/37
PYTHON_CMAKE_BOOL=	TFUN_BUILD_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_STAGEDIR=${STAGEDIR}
PYTHON_BUILD_DEPENDS=	pybind11>0:devel/pybind11

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/thermofun/PyThermoFun${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>

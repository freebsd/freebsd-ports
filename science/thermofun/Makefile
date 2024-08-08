PORTNAME=	thermofun
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code for calculating thermodynamic properties of materials
WWW=		https://github.com/thermohub/thermofun/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		spdlog>0:devel/spdlog
LIB_DEPENDS=	libChemicalFun.so:science/chemicalfun

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	thermohub

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CXXFLAGS+=	-DSPDLOG_FMT_EXTERNAL # see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=258073#c3

TEST_WRKSRC=	${WRKSRC}

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_BUILD_DEPENDS=	pybind11>0:devel/pybind11 \
			${PY_SETUPTOOLS} \
			${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
PYTHON_USES=		python
PYTHON_USE=		PYTHON=pytest
PYTHON_CMAKE_BOOL=	TFUN_BUILD_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_STAGEDIR=${STAGEDIR} -DFREEBSD_PREFIX=${PREFIX}

post-install-PYTHON-on:
	# remove wrong *.pyc, see related bug https://bitbucket.org/gems4/chemicalfun/issues/1/please-support-stagedir
	@${FIND} ${STAGEDIR} -name "*.pyc" -delete
	@${FIND} ${STAGEDIR} -name __pycache__ -delete
	# strip binary
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/thermofun/PyThermoFun${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>

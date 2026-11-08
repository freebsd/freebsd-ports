PORTNAME=	arviz-base
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Base ArviZ features and converters
WWW=		https://python.arviz.org/projects/base/en/latest/ \
		https://github.com/arviz-devs/arviz-base

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy_loader>=0.4:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xarray>=2024.11.0:devel/py-xarray@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5netcdf>0:science/py-h5netcdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	arviz-devs

NO_ARCH=	yes

TEST_ARGS=	--disable-plugin-autoload \
		-k 'not test_convert_to_dataset and not test_convert_to_datatree and not test_clear_data_home and not test_warning_rc_file and not pynvml'
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 1.3.1: 239 passed, 9 deselected (xarray backend plugin / pynvml deprecation / rcparam warning)

.include <bsd.port.mk>

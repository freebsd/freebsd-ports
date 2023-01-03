PORTNAME=	laspy
DISTVERSION=	2.5.2
CATEGORIES=	misc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and tools to read/write LAS files with lidar data
WWW=		https://laspy.readthedocs.io/en/latest/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
# optional dependencies
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}lazrs>=0.5.0:misc/py-lazrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}laszip>=0.2.1:archivers/py-laszip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.8.0:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest # tests can't find the module laspy.cli.core, see https://github.com/laspy/laspy/issues/297

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NOARCH=		yes

.include <bsd.port.mk>

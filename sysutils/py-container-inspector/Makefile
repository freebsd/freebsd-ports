PORTNAME=	container-inspector
DISTVERSION=	33.0.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	container_inspector-${PORTVERSION}

MAINTAINER=	tuukka.pasanen@ilmi.fi
COMMENT=	Analysis utilities and command line tools for Docker container images
WWW=		https://github.com/aboutcode-org/container-inspector

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/apache-2.0.LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=18.1:devel/py-attrs@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}commoncode>=31.2.1:devel/py-commoncode@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}dockerfile-parse>2.0:devel/py-dockerfile-parse@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
PYTEST_BROKEN_TESTS=	test_distro_from_os_release_file

NO_ARCH=	yes

.include <bsd.port.mk>

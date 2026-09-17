PORTNAME=	proxpi
DISTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	michaelo@FreeBSD.org
COMMENT=	PyPI caching mirror
WWW=		https://github.com/EpicWink/proxpi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=2.0<4.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0<4.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.8<7.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27<3.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypercorn>=0.14<2.0:www/py-hypercorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=0.29<2.0:www/py-starlette@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

PYTEST_IGNORED_TESTS=	test_pip_download

NO_ARCH=	yes
# 1.4.0 replaces flask with starlette and is otherwise internally
# incompatible; do not suggest it until the port is updated to match.
PORTSCOUT=	limit:^1\.[0-3]\.

OPTIONS_DEFINE=	FILE
FILE_DESC=	Support file:// index/package URLs

FILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests-file>=2.1.0:www/py-requests-file@${PY_FLAVOR}
FILE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-file-option

.include <bsd.port.mk>

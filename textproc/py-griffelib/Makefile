PORTNAME=	griffelib
DISTVERSION=	2.0.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Signatures for entire Python programs / library components
WWW=		https://github.com/mkdocstrings/griffe

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>=0.7:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4:devel/py-colorama@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	PYPI

PYPI_DESC=	Support for download/inspect packages from PyPI

PYPI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>=24.0:devel/py-pip@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}platformdirs>=4.2:devel/py-platformdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}wheel>=0.42:devel/py-wheel@${PY_FLAVOR}

.include <bsd.port.mk>

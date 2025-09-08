PORTNAME=	vfblib
PORTVERSION=	0.10.4
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for converting FontLab Studio 5 (VFB) files
WWW=		https://github.com/LucasFonts/vfbLib

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=4.59.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.10.15<4:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14.1:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufolib2>=0.18.1:print/py-ufolib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufonormalizer>=0.6.1:x11-fonts/py-ufonormalizer@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL TOML YAML
ALL_DESC=	All optional dependencies
ALL_IMPLIES=	TOML YAML

TOML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomli-w>=1.0.0:textproc/py-tomli-w@${PY_FLAVOR}
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.2:devel/py-pyyaml@${PY_FLAVOR}

.include <bsd.port.mk>

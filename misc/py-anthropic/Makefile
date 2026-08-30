PORTNAME=	anthropic
DISTVERSION=	1.2.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Convenient access to the Anthropic REST API via python
WWW=		https://github.com/anthropics/anthropic-sdk-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.5.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docstring_parser>=0.15:textproc/py-docstring_parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx2>=2.0.0:www/py-httpx2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jiter>=0.4.0:textproc/py-jiter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=1.9.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=0:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

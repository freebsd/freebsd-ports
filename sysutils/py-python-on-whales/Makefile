PORTNAME=	python-on-whales
PORTVERSION=	0.80.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_on_whales-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Docker client for Python, designed to be fun and intuitive
WWW=		https://gabrieldemarmiesse.github.io/python-on-whales/ \
		https://github.com/gabrieldemarmiesse/python-on-whales

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	podman:sysutils/podman \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2<3:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

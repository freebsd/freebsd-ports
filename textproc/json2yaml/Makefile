PORTNAME=	json2yaml
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert JSON to YAML or vice versa
WWW=		https://github.com/drbild/json2yaml

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>=0:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

.include <bsd.port.mk>

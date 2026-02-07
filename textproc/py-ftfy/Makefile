PORTNAME=	ftfy
PORTVERSION=	6.3.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		https://github.com/rspeer/python-ftfy/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fix some problems with Unicode text after the fact
WWW=		https://ftfy.readthedocs.io/en/latest/ \
		https://github.com/rspeer/python-ftfy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wcwidth>=0:devel/py-wcwidth@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>

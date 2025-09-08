PORTNAME=	truststore
PORTVERSION=	0.10.4
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Verify certificates using native system trust stores
WWW=		https://truststore.readthedocs.io/en/latest/ \
		https://github.com/sethmlarson/truststore

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python:3.10+ ssl
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	rabbitpy
PORTVERSION=	3.0.2
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	RabbitMQ client library for Python
WWW=		https://github.com/gmr/rabbitpy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pamqp>=4.0<5.0:net/py-pamqp@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

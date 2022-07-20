PORTNAME=	cirq-google
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google Cirq adapter for IQM's quantum architectures

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=1.14.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.20.0:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.13.0:devel/py-protobuf@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib
GH_PROJECT=	Cirq

WRKSRC_SUBDIR=	cirq-google

NO_ARCH=	yes

.include <bsd.port.mk>

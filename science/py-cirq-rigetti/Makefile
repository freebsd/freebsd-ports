PORTNAME=	cirq-rigetti
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cirq module to run on Rigetti quantum computers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cirq-core>0:science/py-cirq-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=20.3.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2021.5.30:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.8.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.9.0:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpcore>=0.11.1:www/py-httpcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.15.5:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.10:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.14:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.8.2:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt1>=1.7.1:www/py-pyjwt1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyquil>=3.0.0:devel/py-pyquil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcs-api-client>=0.8.0:devel/py-qcs-api-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retrying>=1.3.3:devel/py-retrying@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3339>=6.2:devel/py-rfc3339@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.5.0:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.16.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=1.2.0:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2:textproc/py-toml@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib
GH_PROJECT=	Cirq

WRKSRC_SUBDIR=	cirq-rigetti

NO_ARCH=	yes

.include <bsd.port.mk>

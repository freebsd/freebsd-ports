PORTNAME=	cirq-rigetti
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cirq module to run on Rigetti quantum computers
WWW=		https://github.com/quantumlib/cirq

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired www/py-pyjwt1 (via devel/py-pyquil)
EXPIRATION_DATE=2022-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cirq-core>0:science/py-cirq-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyquil>=3.0.0:devel/py-pyquil@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib
GH_PROJECT=	Cirq

WRKSRC_SUBDIR=	cirq-rigetti

NO_ARCH=	yes

.include <bsd.port.mk>

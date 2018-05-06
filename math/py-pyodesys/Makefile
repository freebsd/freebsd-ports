# $FreeBSD$

PORTNAME=	pyodesys
DISTVERSION=	0.11.14
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Straightforward numerical integration of ODE systems from Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.0.2:math/py-matplotlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sym>=0.3.0:math/py-sym@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.1.1:math/py-sympy@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>

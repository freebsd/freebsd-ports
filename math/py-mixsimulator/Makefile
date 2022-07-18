# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	mixsimulator
PORTVERSION=	0.4.3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Calculate and simulate the least cost of an energy mix under constraints

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	mixsimulator/Experiments/Scenario_type.py

.include <bsd.port.mk>

PORTNAME=	mixsimulator
PORTVERSION=	0.4.6
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Calculate and simulate the least cost of an energy mix under constraints
WWW=		https://github.com/Foloso/MixSimulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	mixsimulator/Experiments/Scenario_type.py

.include <bsd.port.mk>

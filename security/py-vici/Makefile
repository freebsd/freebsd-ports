PORTNAME=	vici
DISTVERSION=	5.9.3
CATEGORIES=	security net-vpn python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Native Python interface for strongSwan's VICI protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-pycodestyle>0:devel/py-pytest-pycodestyle@${PY_FLAVOR}

USES=		python:3.6+ pytest
USE_PYTHON=	autoplist concurrent distutils
PYTEST_ARGS=	--pycodestyle

NO_ARCH=	yes

.include <bsd.port.mk>

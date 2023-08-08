PORTNAME=	vici
DISTVERSION=	5.9.11
CATEGORIES=	security net-vpn python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Native Python interface for strongSwan's VICI protocol
WWW=		https://pypi.org/project/vici/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-pycodestyle>0:devel/py-pytest-pycodestyle@${PY_FLAVOR}

USES=		python pytest
USE_PYTHON=	autoplist concurrent distutils
PYTEST_ARGS=	--pycodestyle

NO_ARCH=	yes

.include <bsd.port.mk>

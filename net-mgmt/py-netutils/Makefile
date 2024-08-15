PORTNAME=	netutils
DISTVERSION=	1.9.0
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Common helper functions useful in network automation
WWW=		https://github.com/networktocode/netutils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		JSONSCHEMA
OPTIONS_DEFAULT=	JSONSCHEMA

JSONSCHEMA_DESC=	ACL check support
JSONSCHEMA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.17.3:devel/py-jsonschema@${PY_FLAVOR}

.include <bsd.port.mk>

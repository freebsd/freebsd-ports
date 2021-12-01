PORTNAME=	netbox-secretstore
DISTVERSION=	1.0.10
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Secret store for NetBox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	netbox>=3.0.0:net-mgmt/netbox \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netbox-plugin-extensions>0:net-mgmt/py-netbox-plugin-extensions@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_VER=${PYTHON_VER}

.include <bsd.port.mk>

PORTNAME=	netbox-secretstore
DISTVERSION=	1.2.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Secret store for NetBox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_VER=${PYTHON_VER}

.include <bsd.port.mk>

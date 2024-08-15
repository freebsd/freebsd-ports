PORTNAME=	netbox-secrets
DISTVERSION=	2.0.3
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	netbox_secrets-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Secret store for NetBox
WWW=		https://github.com/Onemind-Services-LLC/netbox-secrets

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_VER=${PYTHON_VER}

.include <bsd.port.mk>

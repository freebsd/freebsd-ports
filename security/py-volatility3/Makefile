PORTNAME=	volatility3
DISTVERSION=	g20200510
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Advanced memory forensics framework

LICENSE=	VSL
LICENSE_NAME=	Volatility Software License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}capstone>=0:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yara>=0:security/py-yara@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	volatilityfoundation
GH_TAGNAME=	94426ad

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

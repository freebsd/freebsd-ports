PORTNAME=	transmission-rpc
PORTVERSION=	3.4.0
CATEGORIES=	net-p2p python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Python module for Transmission bittorent client JSON-RPC protocol
WWW=		https://pypi.org/project/transmission-rpc/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4.2<5.0.0.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.23.0<3.0.0:www/py-requests@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>

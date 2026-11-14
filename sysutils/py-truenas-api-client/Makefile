PORTNAME=	truenas-api-client
DISTVERSIONPREFIX=	TS-
DISTVERSION=	25.10.8
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	longros@FreeBSD.org
COMMENT=	TrueNAS websocket API client
WWW=		https://github.com/truenas/api_client

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	truenas
GH_PROJECT=	api_client
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|name="truenas_api_client",|&version="${DISTVERSION}",|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>

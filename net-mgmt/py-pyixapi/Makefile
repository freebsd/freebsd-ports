PORTNAME=	pyixapi
DISTVERSION=	0.2.8
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python API client library for IX-API
WWW=		https://ix-api.net/

LICENSE=	APACHE20
#LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-build>=0.9.21:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyjwt>=2.4.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.4:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
#USE_GITHUB=	yes
#GH_ACCOUNT=	peering-manager
#GH_PROJECT=	pyixapi

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|,<0.10.0||' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>

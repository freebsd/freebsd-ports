PORTNAME=	pyixapi
DISTVERSION=	0.3.2
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python API client library for IX-API
WWW=		https://ix-api.net/

LICENSE=	APACHE20
#LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.9.21:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyjwt>=2.15.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.33.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|,<0.13.0||' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>

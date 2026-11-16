PORTNAME=	django-bootstrap4
DISTVERSION=	26.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	alex@xanderio.de
COMMENT=	Bootstrap 4 support for Django projects
WWW=		https://github.com/zostera/django-bootstrap4

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.9.6:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.10.0:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django52>=5.2:www/py-django52@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|"uv_build>=0.9.6,<0.13.0"|"uv_build>=0.9.6"|' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>

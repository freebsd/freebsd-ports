PORTNAME=	drf-spectacular
DISTVERSION=	0.29.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-
DISTNAME=	drf_spectacular-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Sane/flexible OpenAPI 3 schema generation for Django REST framework
WWW=		https://github.com/tfranzel/drf-spectacular

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=Extended support of Django 5.1 ends December 2025, upgrade to the Django 5.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=2025-12-31

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django51>=2.2:www/py-django51@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-djangorestframework>=3.10.3:www/py-dj51-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inflection>=0.3.1:devel/py-inflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritemplate>=2.0.0:net/py-uritemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_DEFINE=		SIDECAR
OPTIONS_DEFAULT=	SIDECAR

SIDECAR_DESC=	Enable self-contained Swagger/Redoc UI installation
SIDECAR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj51-drf-spectacular-sidecar>0:www/py-dj51-drf-spectacular-sidecar@${PY_FLAVOR}

.include <bsd.port.mk>

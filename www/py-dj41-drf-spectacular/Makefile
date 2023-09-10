PORTNAME=	drf-spectacular
DISTVERSION=	0.26.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj41-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Sane/flexible OpenAPI 3 schema generation for Django REST framework
WWW=		https://github.com/tfranzel/drf-spectacular

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 4.1 ends December 2023, upgrade to the Django 4.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2023-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>=2.2:www/py-django41@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-djangorestframework>=3.10.3:www/py-dj41-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inflection>=0.3.1:devel/py-inflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritemplate>=2.0.0:net/py-uritemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_DEFINE=		SIDECAR
OPTIONS_DEFAULT=	SIDECAR

SIDECAR_DESC=	Enable self-contained Swagger/Redoc UI installation
SIDECAR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj41-drf-spectacular-sidecar>0:www/py-dj41-drf-spectacular-sidecar@${PY_FLAVOR}

.include <bsd.port.mk>

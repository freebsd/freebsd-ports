PORTNAME=	drf-yasg
DISTVERSION=	1.21.10
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Yet Another Swagger Generator
WWW=		https://github.com/axnsan12/drf-yasg

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.0.6:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=2.2.16:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.10.3:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inflection>=0.3.1:devel/py-inflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2021.1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritemplate>=3.0.0:net/py-uritemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_DEFINE=		VALIDATION
OPTIONS_DEFAULT=	VALIDATION

VALIDATION_DESC=	Enable built-in OpenAPI validation mechanisms

VALIDATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}swagger-spec-validator>=2.1.0:devel/py-swagger-spec-validator@${PY_FLAVOR}

.include <bsd.port.mk>

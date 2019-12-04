# $FreeBSD$

PORTNAME=	drf-yasg
DISTVERSION=	1.17.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj21-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Yet Another Swagger Generator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

DEPRECATED=		Django 2.1 is now End-of-Life (Since December 2 2019) and no longer supported. Switch to Django 2.2+ versions of this port as soon as possible
EXPIRATION_DATE=	2020-01-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.0.6:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django21>=1.11.7:www/py-django21@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-djangorestframework>=3.8:www/py-dj21-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coreapi>=2.3.3:devel/py-coreapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coreschema>=0.0.4:devel/py-coreschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inflection>=0.3.1:devel/py-inflection@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15.34:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}swagger-spec-validator>=2.1.0:devel/py-swagger-spec-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritemplate>=3.0.0:net/py-uritemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}drf-yasg \
			${PYTHON_PKGNAMEPREFIX}dj22-drf-yasg

.include <bsd.port.mk>

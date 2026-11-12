PORTNAME=	django-pglocks
DISTVERSION=	2.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_pglocks-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Provides useful context managers for advisory locks for PostgreSQL
WWW=		https://github.com/Xof/django-pglocks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	Deprecated by upstream, the package functionality now lives in django-pgware. Please use databases/py-django-pgware instead
EXPIRATION_DATE=2026-12-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=4.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pgware>=1.0.0:databases/py-django-pgware@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

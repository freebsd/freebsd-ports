PORTNAME=	django-pglocks
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Provides useful context managers for advisory locks for PostgreSQL
WWW=		https://github.com/Xof/django-pglocks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Deprecated by upstream, the package functionality now lives in django-pgware. Please use databases/py-django-pgware instead
EXPIRATION_DATE=2026-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.0.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

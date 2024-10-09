PORTNAME=	django-graphql-jwt
DISTVERSION=	0.4.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	JSON Web Token for Django GraphQL
WWW=		https://github.com/flavors/django-graphql-jwt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=2.0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene>=2.1.5:devel/py-graphene@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene-django>=3.0.0:devel/py-graphene-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2:www/py-pyjwt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

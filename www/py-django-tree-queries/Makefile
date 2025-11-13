PORTNAME=	django-tree-queries
DISTVERSION=	0.22.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_tree_queries-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Tree queries with explicit opt-in, without configurability
WWW=		https://github.com/feincms/django-tree-queries

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=		yes

OPTIONS_DEFINE=	ADMIN

ADMIN_DESC=	Tree management support for Django admin

ADMIN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-js-asset>0:www/py-django-js-asset@${PY_FLAVOR}

.include <bsd.port.mk>

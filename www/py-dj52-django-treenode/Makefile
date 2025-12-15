PORTNAME=	django-treenode
PORTVERSION=	0.23.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Abstract model/admin for trees in Django
WWW=		https://github.com/fabiocaccamo/django-treenode

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=5.2:www/py-django52@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>

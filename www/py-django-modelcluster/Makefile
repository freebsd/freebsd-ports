PORTNAME=	django-modelcluster
PORTVERSION=	6.4.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_modelcluster-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django extension for working with clusters of models as a single unit
WWW=		https://github.com/wagtail/django-modelcluster

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	TAGGIT
TAGGIT_DESC=	Tagging support

TAGGIT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-taggit>=3.1:www/py-django-taggit@${PY_FLAVOR}

.include <bsd.port.mk>

PORTNAME=	django-modelcluster
PORTVERSION=	6.2.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Django extension for working with clusters of models as a single unit
WWW=		https://github.com/wagtail/django-modelcluster

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2022.4,1:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	TAGGIT
TAGGIT_DESC=	Tagging support

TAGGIT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj42-django-taggit>=3.1:www/py-dj42-django-taggit@${PY_FLAVOR}

.include <bsd.port.mk>

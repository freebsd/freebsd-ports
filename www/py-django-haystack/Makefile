PORTNAME=	django-haystack
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	www databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pluggable search for Django
WWW=		https://haystacksearch.org/ \
		https://github.com/django-haystack/django-haystack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=2.2:www/py-django32@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ELASTIC
OPTIONS_DEFAULT=ELASTIC
ELASTIC_DESC=	Elasticsearch support

ELASTIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elasticsearch>=5<8:textproc/py-elasticsearch@${PY_FLAVOR}

.include <bsd.port.mk>

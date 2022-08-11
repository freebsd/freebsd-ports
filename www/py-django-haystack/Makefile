PORTNAME=	django-haystack
PORTVERSION=	3.2.1
CATEGORIES=	www databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pluggable search for Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=2.2:www/py-django32@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ELASTIC
OPTIONS_DEFAULT=ELASTIC
ELASTIC_DESC=	Elasticsearch support

ELASTIC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elasticsearch>=5<8:textproc/py-elasticsearch@${PY_FLAVOR}

.include <bsd.port.mk>

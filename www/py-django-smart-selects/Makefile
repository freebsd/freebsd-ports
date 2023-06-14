PORTNAME=	django-smart-selects
PORTVERSION=	1.5.9
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gatemken@cisco.com
COMMENT=	Quickly filter or group "chained" models
WWW=		https://github.com/jazzband/django-smart-selects

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${FILESDIR}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django32>0:www/py-django32@${PY_FLAVOR}

USES=		python:run
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

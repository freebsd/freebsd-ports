PORTNAME=	django-smart-selects
PORTVERSION=	1.5.9
CATEGORIES=	www
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gatemken@cisco.com
COMMENT= 	Quickly filter or group "chained" models

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${FILESDIR}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django22>0:www/py-django22@${PY_FLAVOR}

USES=		python:3.6+,run
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

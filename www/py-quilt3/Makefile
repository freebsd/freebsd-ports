# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	quilt3
PORTVERSION=	3.6.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python client for Quilt data hub

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aws-requests-auth>=0.4.2:devel/py-aws-requests-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>=1.10.0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.16.0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>=0:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-json>=0:www/py-flask-json@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonlines>=1.2.0:devel/py-jsonlines@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=3.0<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.12.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-futures>=1.0.0:www/py-requests-futures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=5.1.1:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.32:misc/py-tqdm@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

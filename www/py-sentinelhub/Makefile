# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	sentinelhub
PORTVERSION=	3.6.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sentinel Hub Utilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aenum>=2.1.4:devel/py-aenum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dataclasses-json>=0:devel/py-dataclasses-json@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=2.2.0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=1.0.0:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>=0:devel/py-shapely@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tifffile>=2020.9.30:graphics/py-tifffile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}utm>=0:graphics/py-utm@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AWS
AWS_DESC=	AWS support

AWS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=0:www/py-boto3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}botocore>=0:devel/py-botocore@${PY_FLAVOR}

.include <bsd.port.mk>

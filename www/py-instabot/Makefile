# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	instabot
PORTVERSION=	0.26.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Instagram bot scripts and API wrapper

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.17.1:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huepy>=0.9.8.1:misc/py-huepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=0.24:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=1.6.8:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.8.0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0.10.5:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}schedule>=0.6.0:devel/py-schedule@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.30.0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

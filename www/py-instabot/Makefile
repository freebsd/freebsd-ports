# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	instabot
PORTVERSION=	0.117.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Instagram bot scripts and API wrapper

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2019.11.28:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3.0.4:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.18.2:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huepy>=1.2.1:misc/py-huepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.8:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=3.0.5:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moviepy>=1.0.1:multimedia/py-moviepy@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=1.7.1:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2019.3:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=0.9.1:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0.10.9:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}schedule>=0.6.0:devel/py-schedule@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.14.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.41.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.7:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

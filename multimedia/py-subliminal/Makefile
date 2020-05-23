# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	subliminal
PORTVERSION=	2.0.5
PORTREVISION=	2
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ed.arrakis@gmail.com
COMMENT=	Python library to search and download subtitles

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.4.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enzyme>=0.4.1:multimedia/py-enzyme@${PY_FLAVOR} \
		${PY_FUTURES} \
		${PYTHON_PKGNAMEPREFIX}guessit>=2.1.0:multimedia/py-guessit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=4.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.0.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=2.3.0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysrt>=1.0.1:textproc/py-pysrt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}babelfish>=0.5.2:devel/py-babelfish@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.6.0:devel/py-dogpile.cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}appdirs>=1.3:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rarfile>=2.7:archivers/py-rarfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2012c:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

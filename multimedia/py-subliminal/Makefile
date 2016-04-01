# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	subliminal
PORTVERSION=	1.1.1
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python library to search and download subtitles

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bs4/__init__.py:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.2.0:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}enzyme>=0.4.1:multimedia/py-enzyme \
		${PYTHON_PKGNAMEPREFIX}guessit>=0.9.1:multimedia/py-guessit \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}click>=4.0:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.0.0:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}chardet>=2.3.0:textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}pysrt>=1.0.1:textproc/py-pysrt \
		${PYTHON_PKGNAMEPREFIX}babelfish>=0.5.2:devel/py-babelfish \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.5.4:devel/py-dogpile.cache \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six

USE_GITHUB=	yes
GH_ACCOUNT=	Diaoul

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	subliminal
PORTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python library to search and download subtitles

LICENSE=	LGPL3

USE_GITHUB=	yes
GH_ACCOUNT=	Diaoul
GH_COMMIT=	f41fc2b
GH_TAGNAME=	${GH_COMMIT}

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bs4/__init__.py:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}enzyme>=0.4.0:${PORTSDIR}/multimedia/py-enzyme \
		${PYTHON_PKGNAMEPREFIX}guessit>=0.6.2:${PORTSDIR}/multimedia/py-guessit \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.999:${PORTSDIR}/www/py-html5lib \
		${PYTHON_PKGNAMEPREFIX}chardet>0:${PORTSDIR}/textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}pysrt>=1.0.1:${PORTSDIR}/textproc/py-pysrt \
		${PYTHON_PKGNAMEPREFIX}babelfish>=0.4.0:${PORTSDIR}/devel/py-babelfish \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.5.2:${PORTSDIR}/devel/py-dogpile.cache \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.25:${PORTSDIR}/devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	subliminal
PORTVERSION=	2.0.3
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python library to search and download subtitles

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.4.0:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}enzyme>=0.4.1:multimedia/py-enzyme \
		${PYTHON_PKGNAMEPREFIX}guessit>=2.0.1:multimedia/py-guessit \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}click>=4.0:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.0.0:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}chardet>=2.3.0:textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}pysrt>=1.0.1:textproc/py-pysrt \
		${PYTHON_PKGNAMEPREFIX}babelfish>=0.5.2:devel/py-babelfish \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.6.0:devel/py-dogpile.cache \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}appdirs>=1.3:devel/py-appdirs \
		${PYTHON_PKGNAMEPREFIX}rarfile>=2.7:archivers/py-rarfile \
		${PYTHON_PKGNAMEPREFIX}pytz>=2012c:devel/py-pytz

USES=		python:2.7+
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>0:devel/py-futures
.endif

.include <bsd.port.post.mk>

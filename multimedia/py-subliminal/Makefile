# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	subliminal
PORTVERSION=	2.0.5
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python library to search and download subtitles

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.4.0:www/py-beautifulsoup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enzyme>=0.4.1:multimedia/py-enzyme@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}guessit>=2.1.0:multimedia/py-guessit@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=4.0:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.0.0:devel/py-stevedore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=2.3.0:textproc/py-chardet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysrt>=1.0.1:textproc/py-pysrt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}babelfish>=0.5.2:devel/py-babelfish@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.6.0:devel/py-dogpile.cache@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}appdirs>=1.3:devel/py-appdirs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rarfile>=2.7:archivers/py-rarfile@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2012c:devel/py-pytz@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>0:devel/py-futures@${FLAVOR}
.endif

.include <bsd.port.post.mk>

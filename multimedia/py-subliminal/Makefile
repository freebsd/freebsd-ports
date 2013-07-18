# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	subliminal
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python library to search and download subtitles

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bs4/__init__.py:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}enzyme>=0.1:${PORTSDIR}/multimedia/py-enzyme \
		${PYTHON_PKGNAMEPREFIX}guessit>=0.4.1:${PORTSDIR}/multimedia/py-guessit \
		${PYTHON_PKGNAMEPREFIX}requests>=1.1:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:${PORTSDIR}/www/py-html5lib \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	bin/subliminal \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 270
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>=1.1:${PORTSDIR}/devel/py-argparse
.endif

.include <bsd.port.post.mk>

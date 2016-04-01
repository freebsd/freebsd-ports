# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	guessit
PORTVERSION=	0.11.0
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Extract as much information as possible from a video file

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfish>=0.5.4:devel/py-babelfish \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}stevedore>=0.14:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}enzyme>=0:multimedia/py-enzyme

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

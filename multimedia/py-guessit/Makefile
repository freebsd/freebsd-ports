# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	guessit
PORTVERSION=	0.8
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Extract as much information as possible from a video file

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfish>=0.5.3:${PORTSDIR}/devel/py-babelfish \
		${PYTHON_PKGNAMEPREFIX}stevedore>=0.14:${PORTSDIR}/devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}requests>=0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}enzyme>=0:${PORTSDIR}/multimedia/py-enzyme

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

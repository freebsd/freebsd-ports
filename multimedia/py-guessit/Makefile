# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	guessit
PORTVERSION=	0.7.1
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Extract as much information as possible from a video file

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfish>=0.5.1:${PORTSDIR}/devel/py-babelfish \
		${PYTHON_PKGNAMEPREFIX}stevedore>=0.14:${PORTSDIR}/devel/py-stevedore

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>

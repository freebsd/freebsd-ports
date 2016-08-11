# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	guessit
PORTVERSION=	2.0.5
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Extract as much information as possible from a video file

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfish>=0.5.5:devel/py-babelfish \
		${PYTHON_PKGNAMEPREFIX}dateutil<2.5.2:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}rebulk>=0.7.1:devel/py-rebulk

USES=		python
USE_PYTHON=	distutils autoplist

post-patch:
		@${REINPLACE_CMD} -e '/setup_requires/d' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>

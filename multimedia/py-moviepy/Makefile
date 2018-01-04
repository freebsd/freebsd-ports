# $FreeBSD$

PORTNAME=	moviepy
PORTVERSION=	0.2.2.13
PORTREVISION=	2
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Video editing with Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

RUN_DEPENDS=	convert:graphics/ImageMagick \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>0:graphics/py-imageio@${FLAVOR} \
		${PYTHON_SITELIBDIR}/cv.py:graphics/py-opencv@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

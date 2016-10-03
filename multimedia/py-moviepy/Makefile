# $FreeBSD$

PORTNAME=	moviepy
PORTVERSION=	0.2.2.11
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Video editing with Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

RUN_DEPENDS=	convert:graphics/ImageMagick \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm \
		${PYTHON_PKGNAMEPREFIX}imageio>0:graphics/py-imageio \
		${PYTHON_SITELIBDIR}/cv.py:graphics/py-opencv2 \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

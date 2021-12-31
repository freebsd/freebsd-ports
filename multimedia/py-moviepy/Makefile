PORTNAME=	moviepy
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Video editing with Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

DEPRECATED=	Depends on expired devel/py-decorator4
EXPIRATION_DATE=2022-03-31

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${PYTHON_PKGNAMEPREFIX}decorator4>=4.0.2<5.0:devel/py-decorator4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>=2.5<3.0:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio-ffmpeg>=0.2.0:graphics/py-imageio-ffmpeg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proglog<=1.0.0:devel/py-proglog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.8.1<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.11.2<5.0:misc/py-tqdm@${PY_FLAVOR} \

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_SINGLE=	IMAGEMAGICK
OPTIONS_SINGLE_IMAGEMAGICK=	IMAGEMAGICK6 IMAGEMAGICK7
OPTIONS_DEFAULT=IMAGEMAGICK7
IMAGEMAGICK6_DESC=	Use ImageMagick 6.x as backend
IMAGEMAGICK7_DESC=	Use ImageMagick 7.x as backend

IMAGEMAGICK6_USES=	magick:6,run
IMAGEMAGICK7_USES=	magick:7,run

.include <bsd.port.mk>

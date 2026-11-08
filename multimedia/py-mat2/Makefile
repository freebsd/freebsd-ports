PORTNAME=	mat2
DISTVERSION=	0.15.0
CATEGORIES=	multimedia audio graphics textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Handy tool to trash your metadata
WWW=		https://pypi.org/project/mat2/

LICENSE=	LGPL3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycairo>0:graphics/py-pycairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR} \
		gdk-pixbuf2>0:graphics/gdk-pixbuf2 \
		librsvg2-rust>0:graphics/librsvg2-rust \
		poppler-glib>0:graphics/poppler-glib

USES=		gnome python
USE_GNOME=	pygobject3:run
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		EXIFTOOL FFMPEG
OPTIONS_DEFAULT=	EXIFTOOL FFMPEG
EXIFTOOL_DESC=		EXIF metadata support via p5-Image-ExifTool
EXIFTOOL_RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool
FFMPEG_RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

.include <bsd.port.mk>

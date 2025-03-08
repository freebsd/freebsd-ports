PORTNAME=	ffmpeg-python
DISTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for FFmpeg - with complex filtering support
WWW=		https://github.com/kkroening/ffmpeg-python

LICENSE=	APACHE20

DEPRECATED=	Depends on expired devel/py-pytest-runner
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		ffmpeg:multimedia/ffmpeg

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	moviepy
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Video editing with Python
WWW=		https://zulko.github.io/moviepy/ \
		https://github.com/Zulko/moviepy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${PYTHON_PKGNAMEPREFIX}decorator>=4.0.2<6.0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>=2.5<3.0:graphics/py-imageio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio-ffmpeg>=0.2.0:graphics/py-imageio-ffmpeg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.25.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proglog>=0<1.0.0_99:devel/py-proglog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.2.0<12.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.10:www/py-python-dotenv@${PY_FLAVOR}

USES=		magick:run python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

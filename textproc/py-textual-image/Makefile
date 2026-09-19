PORTNAME=	textual-image
PORTVERSION=	0.14.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	textual_image-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Render images via Kitty's Terminal Graphics Protocol with Rich and Textual
WWW=		https://github.com/lnqs/textual-image

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=10.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.4.0:textproc/py-rich@${PY_FLAVOR}

USES=		python:3.12+ shebangfix
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SOURCE_DATE_EPOCH=315532800 # 1980-01-01 00:00:00 UTC
NO_ARCH=	yes

SHEBANG_FILES=	textual_image/__main__.py \
		textual_image/demo/*.py

OPTIONS_DEFINE=	NUMPY TEXTUAL
TEXTUAL_DESC=	Textual support

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0,1:math/py-numpy@${PY_FLAVOR}
TEXTUAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}textual>=0.68.0:textproc/py-textual@${PY_FLAVOR}

.include <bsd.port.mk>

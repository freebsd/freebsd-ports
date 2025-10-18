PORTNAME=	textual-image
PORTVERSION=	0.8.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	textual_image-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Render images via Kitty's Terminal Graphics Protocol with Rich and Textual
WWW=		https://github.com/lnqs/textual-image

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=10.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.4.0:textproc/py-rich@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	TEXTUAL
TEXTUAL_DESC=	Textual support

TEXTUAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}textual>=0.68.0:textproc/py-textual@${PY_FLAVOR}

.include <bsd.port.mk>

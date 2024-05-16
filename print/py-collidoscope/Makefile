PORTNAME=	collidoscope
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Brute force detection of glyph collisions
WWW=		https://github.com/simoncozens/collidoscope

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beziers>=0.0.3:graphics/py-beziers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glyphtools>=0:print/py-glyphtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0:print/py-uharfbuzz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

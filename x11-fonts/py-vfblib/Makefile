PORTNAME=	vfblib
PORTVERSION=	0.7.1
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for converting FontLab Studio 5 (VFB) files
WWW=		https://github.com/LucasFonts/vfbLib

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=4.45.1:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.8.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufolib2>=0.16.0:print/py-ufolib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufonormalizer>=0.6.1:x11-fonts/py-ufonormalizer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

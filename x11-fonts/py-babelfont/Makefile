PORTNAME=	babelfont
PORTVERSION=	3.1.3
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Abstract interface to font source files based on fontParts
WWW=		https://github.com/simoncozens/babelfont

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=4.53.1:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openstep-plist>=0.2.2:textproc/py-openstep-plist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.5.1:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufolib2>=0.16.0:print/py-ufolib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ufomerge>=1.8.0:print/py-ufomerge@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	READ_TTF VFB
READ_TTF_DESC=	TrueType Font (TTF) files support
VFB_DESC=	FontLab Studio 5 (VFB) files support

READ_TTF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fontfeatures>=1.8.0:x11-fonts/py-fontfeatures@${PY_FLAVOR}
VFB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vfblib>=0.9.0:x11-fonts/py-vfblib@${PY_FLAVOR}

.include <bsd.port.mk>

PORTNAME=	fontfeatures
PORTVERSION=	1.9.0
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library for manipulating OpenType font features
WWW=		https://github.com/simoncozens/fontFeatures

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=4.54.0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	SHAPER
SHAPER_DESC=	Unicode shaping engine support

SHAPER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfont>=3.0.0:x11-fonts/py-babelfont@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}youseedee>=0.3.0:textproc/py-youseedee@${PY_FLAVOR}

.include <bsd.port.mk>

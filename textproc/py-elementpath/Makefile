PORTNAME=	elementpath
DISTVERSION=	4.8.0
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	XPath 1.0/2.0/3.0 parsers and selectors for ElementTree and lxml
WWW=		https://github.com/sissaschool/elementpath

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xmlschema>=2.0.0:textproc/py-xmlschema@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>

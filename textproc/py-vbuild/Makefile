PORTNAME=	vbuild
DISTVERSION=	0.8.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Simple module to extract html/script/style from a VueJS file
WWW=		https://github.com/manatlan/vbuild

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry>=0:devel/py-poetry@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pscript>=0:textproc/py-pscript@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

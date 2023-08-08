PORTNAME=	sphinx-basic-ng
PORTVERSION=	1.0.0b2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_basic_ng-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern skeleton for Sphinx themes
WWW=		https://github.com/pradyunsg/sphinx-basic-ng

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=4.0,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

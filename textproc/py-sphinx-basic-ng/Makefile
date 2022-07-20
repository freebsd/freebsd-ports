PORTNAME=	sphinx-basic-ng
PORTVERSION=	0.0.1a12
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_basic_ng-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern skeleton for Sphinx themes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=4.0,1<6.0,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

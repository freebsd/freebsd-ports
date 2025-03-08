PORTNAME=	flask-theme
DISTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Infrastructure for theming support in Flask applications
WWW=		https://github.com/liuliqiang/flask-theme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0.6:www/py-flask@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configparser>0:devel/py-configparser@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils nose

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	iris-intelowl-module
DISTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	IntelOwl IRIS module
WWW=		https://github.com/dfir-iris/iris-intelowl-module

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyintelowl>0:devel/py-pyintelowl@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dfir-iris
GH_TAGNAME=	39744a0396483015347f2d8066219ab773f5c581

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

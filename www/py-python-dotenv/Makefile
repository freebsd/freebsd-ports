# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	python-dotenv
PORTVERSION=	0.18.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add .env support to your django/flask apps

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI
OPTIONS_DEFAULT=CLI
CLI_DESC=	Command-line interface support

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=5.0:devel/py-click@${PY_FLAVOR}

.include <bsd.port.mk>

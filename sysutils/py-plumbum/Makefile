PORTNAME=	plumbum
PORTVERSION=	1.8.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
MASTER_SITES=	PYPI

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shell combinators library
WWW=		https://github.com/tomerfiliba/plumbum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	SSH

SSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR}

.include <bsd.port.mk>

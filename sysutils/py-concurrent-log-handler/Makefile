PORTNAME=	concurrent-log-handler
DISTVERSION=	0.9.19
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	risner@stdio.com
COMMENT=	RotatingFileHandler replacement with concurrency, gzip
WWW=		https://pypi.org/project/concurrent-log-handler/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}portalocker>=1.4.0:devel/py-portalocker@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

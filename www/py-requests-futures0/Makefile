PORTNAME=	requests-futures
PORTVERSION=	0.9.9
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP library written in Python for human beings
WWW=		https://github.com/ross/requests-futures

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.2.0:www/py-requests@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.

.include <bsd.port.mk>

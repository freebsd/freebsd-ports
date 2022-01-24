PORTNAME=	python-utils
PORTVERSION=	3.1.0
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Collection of small functions and classes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

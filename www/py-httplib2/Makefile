PORTNAME=	httplib2
PORTVERSION=	0.20.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Comprehensive HTTP client library

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.4.2:devel/py-pyparsing@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

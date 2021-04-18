# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	opt-einsum
PORTVERSION=	3.3.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opt_einsum-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Optimizing numpys einsum function

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.7,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

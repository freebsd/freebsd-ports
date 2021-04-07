PORTNAME=	rnc2rng
DISTVERSION=	2.6.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	RELAX NG Compact to regular syntax conversion library

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rply>0:devel/py-rply@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>

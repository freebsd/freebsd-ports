PORTNAME=	quantities
DISTVERSION=	0.13.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Support for physical quantities with units, based on numpy

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>

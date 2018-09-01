# $FreeBSD$

PORTNAME=	rapi
DISTVERSION=	0.1.2
CATEGORIES=	math
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/randy3k/${PORTNAME}/commit/
PATCHFILES=	fb8b962651d6bec009f1bf67eb0369e62da134c4.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Minimal R API for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}multipledispatch>0:devel/py-multipledispatch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>

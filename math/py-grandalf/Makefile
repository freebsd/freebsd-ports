PORTNAME=	grandalf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7
CATEGORIES=	math graphics python
#MASTER_SITES=	CHEESESHOP # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graph experimentation and drawing algorithms framework

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	bdcht
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

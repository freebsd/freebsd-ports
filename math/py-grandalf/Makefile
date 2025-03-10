PORTNAME=	grandalf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	math graphics python
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graph experimentation and drawing algorithms framework
WWW=		https://github.com/bdcht/grandalf

LICENSE=	MIT

DEPRECATED=	Depends on expired devel/py-pytest-runner
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	bdcht
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>

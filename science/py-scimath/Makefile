PORTNAME=	scimath
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	science math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Scientific and Mathematical calculations
WWW=		https://pypi.org/project/scimath/

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=0:devel/py-traits@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>

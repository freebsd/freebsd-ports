PORTNAME=	pysrp
DISTVERSION=	1.0.22
PORTREVISION=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Python Secure Remote Password protocol (SRP)
WWW=		https://github.com/cocagne/pysrp

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>1.16.0:devel/py-six@${PY_FLAVOR}

USES=		cpe python
USE_GITHUB=	yes
GH_ACCOUNT=	cocagne
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	pysrp_project

NO_ARCH=	yes

.include <bsd.port.mk>

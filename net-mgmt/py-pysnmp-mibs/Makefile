PORTNAME=	pysnmp-mibs
PORTVERSION=	0.1.6
PORTREVISION=	1
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI \
		SF/pysnmp/pysnmp-mibs/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mhjacks@swbell.net
COMMENT=	Additional python MIB files for pysnmp and friends
WWW=		https://github.com/etingof/pysnmp-mibs

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysnmp>=4.3.2:net-mgmt/py-pysnmp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

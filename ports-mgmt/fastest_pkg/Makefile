PORTNAME=	fastest_pkg
PORTVERSION=	0.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	ports-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	0a736009a0c98d3277e6cfe93cc36a5bc6f6cd40.patch:-p1

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Script to find the fastest pkg mirror

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	ehaupt
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

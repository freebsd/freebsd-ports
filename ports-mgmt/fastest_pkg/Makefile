# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	fastest_pkg
PORTVERSION=	0.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	ports-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Script to find the fastest pkg mirror

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${PY_FLAVOR} \
		curl:ftp/curl

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	ehaupt
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

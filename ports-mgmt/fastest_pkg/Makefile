# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fastest_pkg
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	ports-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Script to find the fastest pkg mirror

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${PY_FLAVOR} \
		curl:ftp/curl

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	ehaupt
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>

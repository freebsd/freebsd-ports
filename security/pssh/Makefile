PORTNAME=	pssh
PORTVERSION=	2.3.5
DISTVERSIONPREFIX=	v
CATEGORIES=	security net sysutils

MAINTAINER=	timp87@gmail.com
COMMENT=	Parallel version of OpenSSH and related tools
WWW=		https://github.com/lilydjwg/pssh

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	rsync:net/rsync

USES=		python:3.5+
USE_PYTHON=	autoplist pep517
USE_GITHUB=	yes
GH_ACCOUNT=	lilydjwg

NO_ARCH=	yes
.include <bsd.port.mk>

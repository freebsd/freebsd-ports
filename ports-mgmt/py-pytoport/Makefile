PORTNAME=	pytoport
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1-4
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g08c2a0f
CATEGORIES=	ports-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate FreeBSD ports from Python modules on PyPI
WWW=		https://github.com/freebsd/pytoport

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired misc/py-spdx-lookup
EXPIRATION_DATE=2025-03-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.12:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-lookup>=0.3.0:misc/py-spdx-lookup@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

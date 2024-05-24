PORTNAME=	ploy_ezjail
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Plugin for ploy to provision FreeBSD jails using ezjail
WWW=		https://github.com/ployground/ploy_ezjail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lazy>0:devel/py-lazy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ploy>=2.0.0:sysutils/py-ploy@${PY_FLAVOR} \
		${PY_SETUPTOOLS}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>

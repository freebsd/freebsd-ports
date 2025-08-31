PORTNAME=	json-repair
DISTVERSION=	0.50.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package to repair broken json strings
WWW=		https://github.com/mangiucugna/json_repair/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.44.0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 0.50.0: 3 failed, 94 passed, 4 errors in 7.12s, see https://github.com/mangiucugna/json_repair/issues/147

.include <bsd.port.mk>

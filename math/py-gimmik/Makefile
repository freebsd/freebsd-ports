PORTNAME=	gimmik
DISTVERSION=	4.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generator of Matrix Multiplication Kernels
WWW=		https://github.com/vincentlab/GiMMiK

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>=1.0.0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.2.0:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	sherlock-project
DISTVERSION=	0.16.0
CATEGORIES=	www net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hunt down social media accounts by username across social networks
WWW=		https://sherlockproject.xyz/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.2.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2019.6.16:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.1<0.5:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=1.7.0<2:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-futures>=1.0.0<2:www/py-requests-futures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>=1.8.0<2:security/py-stem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torrequest>=0.1.0<0.2:www/py-torrequest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.1,1<3,1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0.10<4:textproc/py-openpyxl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

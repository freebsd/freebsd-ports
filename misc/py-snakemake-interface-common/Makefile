PORTNAME=	snakemake-interface-common
DISTVERSION=	1.23.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	snakemake_interface_common-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common functions and classes for Snakemake and its plugins
WWW=		https://github.com/snakemake/snakemake-interface-common

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse-dataclass>=2.0.0:devel/py-argparse-dataclass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>=1.7:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

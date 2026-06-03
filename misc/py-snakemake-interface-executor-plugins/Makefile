PORTNAME=	snakemake-interface-executor-plugins
DISTVERSION=	9.4.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	snakemake_interface_executor_plugins-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Stable interface for Snakemake executor plugins
WWW=		https://github.com/snakemake/snakemake-interface-executor-plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse-dataclass>=2.0.0:devel/py-argparse-dataclass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snakemake-interface-common>=1.19.0:misc/py-snakemake-interface-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}throttler>=1.2.2:devel/py-throttler@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

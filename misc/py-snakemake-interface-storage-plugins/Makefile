PORTNAME=	snakemake-interface-storage-plugins
DISTVERSION=	4.4.1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	snakemake_interface_storage_plugins-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Stable interface for Snakemake storage plugins
WWW=		https://github.com/snakemake/snakemake-interface-storage-plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}humanfriendly>=10.0:textproc/py-humanfriendly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snakemake-interface-common>=1.12.0:misc/py-snakemake-interface-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9.1.4:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}throttler>=1.2.2:devel/py-throttler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.15.0:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

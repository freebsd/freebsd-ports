PORTNAME=	snakemake-interface-logger-plugins
DISTVERSION=	2.0.1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	snakemake_interface_logger_plugins-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Logger plugin interface for Snakemake
WWW=		https://github.com/snakemake/snakemake-interface-logger-plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}snakemake-interface-common>=1.17.4:misc/py-snakemake-interface-common@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

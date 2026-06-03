PORTNAME=	snakemake-interface-scheduler-plugins
DISTVERSION=	2.0.2
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	snakemake_interface_scheduler_plugins-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scheduler plugin interface for Snakemake
WWW=		https://github.com/snakemake/snakemake-interface-scheduler-plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}snakemake-interface-common>=1.20.1:misc/py-snakemake-interface-common@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

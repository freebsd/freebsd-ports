PORTNAME=	snakemake-interface-report-plugins
DISTVERSION=	2.0.1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	snakemake_interface_report_plugins-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interface for Snakemake report plugins
WWW=		https://github.com/snakemake/snakemake-interface-report-plugins

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}snakemake-interface-common>=1.23.0:misc/py-snakemake-interface-common@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

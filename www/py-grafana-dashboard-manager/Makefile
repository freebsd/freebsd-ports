PORTNAME=	grafana-dashboard-manager
DISTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	CLI for saving and restoring Grafana dashboards via HTTP API
WWW=		https://github.com/Beam-Connectivity/grafana-dashboard-manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# XXX: Requires requests>=2.26.0
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.4.0:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

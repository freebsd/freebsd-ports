PORTNAME=	hier-config
DISTVERSION=	2.3.1
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hier_config-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Network config comparison tool used to build remediation configs
WWW=		https://github.com/netdevops/hier_config

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=5.4:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-pyyaml>=6.0.12.12<7:devel/py-types-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

# The 3.x release contains breaking changes and its both consumers,
# py-ciscoconfparse{2}, aren't compatible with it, yet.
PORTSCOUT=	limit:2\.

.include <bsd.port.mk>

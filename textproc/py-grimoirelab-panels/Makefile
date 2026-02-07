PORTNAME=	grimoirelab-panels
DISTVERSION=	1.1.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

# Ask clusteradm@ before removal
MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Dashboards for GrimoireLab
WWW=		https://github.com/chaoss/grimoirelab-sigils

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>

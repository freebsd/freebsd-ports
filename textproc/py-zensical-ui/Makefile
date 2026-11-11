PORTNAME=	zensical-ui
DISTVERSION=	0.0.42
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	zensical_ui-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Templates and browser assets for Zensical
WWW=		https://github.com/zensical/ui/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.27<2.0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

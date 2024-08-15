PORTNAME=	rich-argparse
PORTVERSION=	1.5.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rich_argparse-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rich help formatters for argparse and optparse
WWW=		https://github.com/hamdanal/rich-argparse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.11.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rich>=11.0.0:textproc/py-rich@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

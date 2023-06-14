PORTNAME=	sphinx-argparse
PORTVERSION=	0.4.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_argparse-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sphinx extension that automatically documents argparse
WWW=		https://github.com/ashb/sphinx-argparse

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.0,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

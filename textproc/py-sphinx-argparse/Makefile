PORTNAME=	sphinx-argparse
DISTVERSION=	0.5.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_argparse-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sphinx extension that automatically documents argparse
WWW=		https://github.com/ashb/sphinx-argparse

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.0,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

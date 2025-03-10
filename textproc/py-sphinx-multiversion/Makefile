PORTNAME=	sphinx-multiversion
DISTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Sphinx extension for building self-hosted versioned docs
WWW=		https://github.com/Holzhaus/sphinx-multiversion

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=2.1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	sphinx-multiversion-zrepl

NO_ARCH=	yes

.include <bsd.port.mk>

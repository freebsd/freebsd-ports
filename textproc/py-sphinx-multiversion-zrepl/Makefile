PORTNAME=	sphinx-multiversion
DISTVERSION=	g20230909
PORTREVISION=	1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-zrepl

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Sphinx extension for building self-hosted versioned docs (zrepl fork)
WWW=		https://github.com/zrepl/sphinx-multiversion

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=2.1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	zrepl
GH_TAGNAME=	52c915d

USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	sphinx-multiversion

NO_ARCH=	yes

.include <bsd.port.mk>

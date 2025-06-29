PORTNAME=	sphinx-last-updated-by-git
PORTVERSION=	0.3.8
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_last_updated_by_git-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Get the "last updated" time for each Sphinx page from Git
WWW=		https://github.com/mgeier/sphinx-last-updated-by-git

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	git:devel/git \
		${PYTHON_PKGNAMEPREFIX}sphinx>=1.8,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

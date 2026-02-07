PORTNAME=	sphinxcontrib-devhelp
PORTVERSION=	2.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/-/_/}-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Sphinx extension which outputs Devhelp document
WWW=		https://www.sphinx-doc.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

USES=		python
USE_PYTHON=	autoplist concurrent pep517

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2.0<4:devel/py-flit-core@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	sphinxcontrib-htmlhelp
PORTVERSION=	2.1.0
CATEGORIES=	textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinxcontrib_htmlhelp-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Sphinx extension which renders HTML help files
WWW=		https://www.sphinx-doc.org/en/master/ \
		https://github.com/sphinx-doc/sphinxcontrib-htmlhelp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.7:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	sphinxcontrib-applehelp
PORTVERSION=	2.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Extension which outputs Apple help books
WWW=		https://www.sphinx-doc.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

USES=		python
USE_GITHUB=	yes
GH_TUPLE=	sphinx-doc:sphinxcontrib-applehelp:${PORTVERSION}
USE_PYTHON=	autoplist concurrent pep517 pytest
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
NO_ARCH=	yes

.include <bsd.port.mk>

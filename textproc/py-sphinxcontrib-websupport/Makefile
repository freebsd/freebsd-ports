PORTNAME=	sphinxcontrib-websupport
PORTVERSION=	2.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinxcontrib_websupport-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Integrate Sphinx documentation into your Web application
WWW=		https://github.com/sphinx-doc/sphinxcontrib-websupport

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.7:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=5,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-serializinghtml>=0:textproc/py-sphinxcontrib-serializinghtml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

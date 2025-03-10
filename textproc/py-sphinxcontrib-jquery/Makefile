PORTNAME=	sphinxcontrib-jquery
PORTVERSION=	4.1
CATEGORIES=	textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Request jQuery for use in Sphinx themes or extensions
WWW=		https://github.com/sphinx-contrib/jquery

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.7:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.8:textproc/py-sphinx@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>

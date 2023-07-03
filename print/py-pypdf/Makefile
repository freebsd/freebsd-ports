PORTNAME=	pypdf
PORTVERSION=	3.12.0
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Pure-Python PDF toolkit
WWW=		https://pybrary.net/pyPdf/

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>2:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

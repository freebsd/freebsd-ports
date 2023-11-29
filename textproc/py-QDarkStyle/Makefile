PORTNAME=	QDarkStyle
PORTVERSION=	3.2.3
CATEGORIES=	textproc devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Dark stylesheet for Python and Qt applications
WWW=		https://pypi.org/project/QDarkStyle/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}helpdev>=0.6.10:devel/py-helpdev@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=1.9:devel/py-QtPy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	tldr
PORTVERSION=	3.4.1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jinking.this@gmail.com
COMMENT=	Python command-line client for tldr pages
WWW=		https://github.com/tldr-pages/tldr-python-client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shtab>0:devel/py-shtab@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517 flavors
SHEBANG_FILES=	tldr.py
NO_ARCH=	yes

.include <bsd.port.mk>

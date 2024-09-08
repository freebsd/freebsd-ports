PORTNAME=	tldr
PORTVERSION=	3.3.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jinking.this@gmail.com
COMMENT=	Python command-line client for tldr pages
WWW=		https://github.com/tldr-pages/tldr-python-client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shtab>0:devel/py-shtab@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils flavors

USE_GITHUB=	yes
GH_ACCOUNT=	tldr-pages
GH_PROJECT=	tldr-python-client

NO_ARCH=	yes

.include <bsd.port.mk>

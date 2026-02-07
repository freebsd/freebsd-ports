PORTNAME=	nvdlib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.3
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Simple NIST NVD API wrapper library
WWW=		https://github.com/vehemont/nvdlib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.32.3<3:www/py-requests@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	vehemont
GH_PROJECT=	nvdlib
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

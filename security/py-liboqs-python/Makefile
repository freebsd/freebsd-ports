PORTNAME=	liboqs-python
DISTVERSION=	0.10.0
PORTREVISION=	3
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for quantum-resistant cryptography
WWW=		https://openquantumsafe.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	liboqs.so:security/liboqs

USES=		python
USE_PYTHON=	pep517 autoplist nose2

USE_GITHUB=	yes
GH_ACCOUNT=	open-quantum-safe

NO_ARCH=	yes

.include <bsd.port.mk>

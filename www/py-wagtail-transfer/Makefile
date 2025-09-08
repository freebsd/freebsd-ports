PORTNAME=	wagtail-transfer
PORTVERSION=	0.10
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Content transfer for Wagtail
WWW=		https://github.com/wagtail/wagtail-transfer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wagtail>=5.2:www/py-wagtail@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wagtail

.include <bsd.port.mk>

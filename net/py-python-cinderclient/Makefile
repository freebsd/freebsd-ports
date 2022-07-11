# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>

PORTNAME=	python-cinderclient
PORTVERSION=	8.3.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Block Storage API Client Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keystoneauth1>=4.3.1:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=5.0.1:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=4.8.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=5.5.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable0>=0.7.2:devel/py-prettytable0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=3.5.1:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=3.3.0:devel/py-stevedore@${PY_FLAVOR}

USES=		python:3.8+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_GLOB=	*.sh

.include <bsd.port.mk>

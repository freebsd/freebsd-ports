# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>

PORTNAME=	python-glanceclient
PORTVERSION=	3.4.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Image API Client Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keystoneauth1>=3.6.2:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable0>=0.7.1:devel/py-prettytable0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=17.1.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}warlock>=1.2.0<2:devel/py-warlock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.7.0:devel/py-wrapt@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/glance|${PREFIX}&|g' ${WRKSRC}/glanceclient/shell.py

.include <bsd.port.mk>

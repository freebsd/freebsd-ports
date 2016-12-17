# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	python-glanceclient
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Client for the OpenStack Glance API

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=0:net/py-python-keystoneclient \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}warlock>=0:devel/py-warlock \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils

USES=		python shebangfix
SHEBANG_FILES=	glanceclient/tests/functional/hooks/post_test_hook.sh
USE_PYTHON=	distutils autoplist noegginfo
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,install_requires.*,,' ${WRKSRC}/setup.py

.include <bsd.port.mk>

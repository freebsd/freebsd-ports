# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	python-ceilometerclient
PORTVERSION=	2.9.0
PORTREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Telemetry API Client Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0.7<0.8:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.8.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.10.0:devel/py-stevedore@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_GLOB=	*.sh

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}keystoneauth13>=2.1.0:devel/py-keystoneauth13@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n3>=2.1.0:devel/py-oslo.i18n3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization2>=1.10.0:devel/py-oslo.serialization2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils3>=3.17.0:devel/py-oslo.utils3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.1.0:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.17.0:devel/py-oslo.utils@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>

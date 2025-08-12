PORTNAME=	google-cloud-core
PORTVERSION=	2.4.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	google_cloud_core-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API Client library for Google Cloud: Core Helpers
WWW=		https://github.com/googleapis/python-cloud-core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.3.1<3.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=1.25.0<3.0.0:security/py-google-auth@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	GRPC
OPTIONS_DEFAULT=GRPC

GRPC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=1.38.0<2.0:devel/py-grpcio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}grpcio-status>=1.38.0<2.0.0:devel/py-grpcio-status@${PY_FLAVOR}

.include <bsd.port.mk>

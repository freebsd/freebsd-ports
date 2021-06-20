# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	google-api-core
PORTVERSION=	1.30.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core Google API Client Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-auth>=1.25.0<2.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>=1.6.0<2.0:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=14.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.12.0,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.0<3.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.13.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	GRPC GRPCGCP
OPTIONS_DEFAULT=GRPC
GRPC_DESC=	gRPC support
GRPCGCP_DESC=	gRPC support for GCP

GRPC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=1.29.0<2.0:devel/py-grpcio@${PY_FLAVOR}
GRPCGCP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio-gcp>=0.2.2:devel/py-grpcio-gcp@${PY_FLAVOR}

.include <bsd.port.mk>

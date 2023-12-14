PORTNAME=	google-api-core
PORTVERSION=	2.15.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core Google API Client Library
WWW=		https://github.com/googleapis/python-api-core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-auth>=2.14.1<3.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>=1.56.2<2.0:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.6,1<5.0.0,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.0<3.0.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	GRPC GRPCGCP
OPTIONS_DEFAULT=GRPC
GRPCGCP_DESC=	gRPC support for Google Cloud Platform

GRPC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=1.49.1<2.0:devel/py-grpcio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}grpcio-status>=1.49.1<2.0:devel/py-grpcio-status@${PY_FLAVOR}
GRPCGCP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio-gcp>=0.2.2<1.0:devel/py-grpcio-gcp@${PY_FLAVOR}

.include <bsd.port.mk>

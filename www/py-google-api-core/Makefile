# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	google-api-core
PORTVERSION=	2.8.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core Google API Client Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-auth>=1.25.0<3.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>=1.56.2<2.0:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.15.0,1<5.0.0,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.0<3.0.0:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	GRPC
OPTIONS_DEFAULT=GRPC
GRPC_DESC=	gRPC support

GRPC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio>=1.33.2<2.0:devel/py-grpcio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}grpcio-status>=1.33.2<2.0:devel/py-grpcio-status@${PY_FLAVOR}

.include <bsd.port.mk>

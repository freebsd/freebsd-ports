PORTNAME=	google-cloud-dlp
PORTVERSION=	3.13.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cloud Data Loss Prevention (DLP) API API client library
WWW=		https://github.com/googleapis/google-cloud-python/tree/main/packages/google-cloud-dlp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-core>=2.10.0<3.0.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.22.2<2.0.0:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.6,1<5.0.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	LIBCST
LIBCST_DESC=	Concrete Syntax Tree (CST) support

LIBCST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcst03>=0.2.5:devel/py-libcst03@${PY_FLAVOR}

.include <bsd.port.mk>

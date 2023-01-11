PORTNAME=	google-cloud-audit-log
PORTVERSION=	0.2.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Cloud Audit Protos
WWW=		https://github.com/googleapis/python-audit-log

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>=1.56.2<2.0:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.6.0,1<5.0.0,1:devel/py-protobuf@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

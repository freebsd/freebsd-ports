PORTNAME=	s3transfer
PORTVERSION=	0.8.2
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Amazon S3 Transfer Manager for Python
WWW=		https://github.com/boto/s3transfer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.33.2<2.0.0:devel/py-botocore@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes

.include <bsd.port.mk>

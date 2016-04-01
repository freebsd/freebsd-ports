# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pynsq
PORTVERSION=	0.6.9
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Official Python client library for NSQ

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}python-snappy>0:archivers/py-python-snappy \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson

USES=		python:-2.7
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	bitly

NO_ARCH=	yes

# test_reader requires nsqd(8)
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test -a "--ignore=tests/test_reader.py"

.include <bsd.port.mk>

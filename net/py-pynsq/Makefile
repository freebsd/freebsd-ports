# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	pynsq
PORTVERSION=	0.9.0b1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Official Python client library for NSQ

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado5<6:www/py-tornado5@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.3.1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-snappy>0:archivers/py-python-snappy@${PY_FLAVOR} \
		nsqd:net/nsq

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	nsqio

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>

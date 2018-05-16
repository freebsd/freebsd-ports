# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch-dsl
PORTVERSION=	6.1.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbaggs2016@gmail.com
COMMENT=	High level Python client for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch>=6.1.0:textproc/py-elasticsearch@${FLAVOR} \
		${PY_IPADDRESS} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>

PORTNAME=	rabbitmq-c
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMESUFFIX=	-devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	RabbitMQ C AMQP client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson@${PY_FLAVOR}

CONFLICTS=	rabbitmq-c

USES=		cmake pathfix python ssl
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	alanxz

OPTIONS_DEFINE=	POPT
OPTIONS_SUB=	yes
POPT_DESC=	Popt support in tools
POPT_LIB_DEPENDS=	libpopt.so:devel/popt

.include <bsd.port.mk>

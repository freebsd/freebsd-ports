PORTNAME=	maxminddb
PORTVERSION=	2.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Python module for reading MaxMind DB file
WWW=		https://github.com/maxmind/MaxMind-DB-Reader-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		compiler:c11 localbase python
USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	MaxMind-DB-Reader-python

USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

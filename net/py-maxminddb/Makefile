PORTNAME=	maxminddb
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Python module for reading MaxMind DB file
WWW=		https://github.com/maxmind/MaxMind-DB-Reader-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

USES=		compiler:c11 localbase python
USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	MaxMind-DB-Reader-python
GH_TAGNAME=	d8accfe

USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/maxminddb/extension*.so

.include <bsd.port.mk>

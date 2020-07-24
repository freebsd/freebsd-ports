# Created by: Olivier Cochard-Labbé <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	maxminddb
PORTVERSION=	2.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Python module for reading MaxMind DB file

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
RUN_DEPENDS=	${PY_IPADDRESS}

USES=		compiler:c11 localbase python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	MaxMind-DB-Reader-python

USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/maxminddb/extension.so

.include <bsd.port.mk>

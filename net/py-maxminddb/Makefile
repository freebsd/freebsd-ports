# Created by: Olivier Cochard-Labbé <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	maxminddb
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@cochard.me
COMMENT=	Python module for reading MaxMind DB file

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipaddr>0:${PORTSDIR}/devel/py-ipaddr
LIB_DEPENDS=	libmaxminddb.so:${PORTSDIR}/net/libmaxminddb

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	MaxMind-DB-Reader-python

USES=		python
USE_PYTHON=	autoplist distutils

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>

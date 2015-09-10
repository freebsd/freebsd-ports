# Created by: Olivier Cochard-Labbé <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	GeoIP2
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@cochard.me
COMMENT=	MaxMind GeoIP2 Python API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}maxminddb>0:${PORTSDIR}/net/py-maxminddb

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	GeoIP2-python

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

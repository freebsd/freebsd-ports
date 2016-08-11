# Created by: Olivier Cochard-Labbé <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GeoIP2
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	MaxMind GeoIP2 Python API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maxminddb>=1.1.0:net/py-maxminddb \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4:www/py-requests

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	GeoIP2-python

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

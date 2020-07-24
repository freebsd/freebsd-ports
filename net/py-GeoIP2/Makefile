# Created by: Olivier Cochard-Labbé <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GeoIP2
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	MaxMind GeoIP2 Python API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maxminddb>=1.5.2:net/py-maxminddb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.2:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+

GH_ACCOUNT=	maxmind
GH_PROJECT=	GeoIP2-python

NO_ARCH=	yes
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>

# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	folium
PORTVERSION=	0.5.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Make beautiful maps with Leaflet.js & Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}branca>=0:www/py-branca@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>

# Created by: Mike Meyer
# $FreeBSD$

PORTNAME=	beautifulsoup4
PORTVERSION=	4.8.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	48

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML/XML Parser for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}soupsieve>=1.2:www/py-soupsieve@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	ignore:1

.include <bsd.port.mk>

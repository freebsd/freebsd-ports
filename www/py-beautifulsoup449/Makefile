PORTNAME=	beautifulsoup4
PORTVERSION=	4.9.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	49

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML/XML Parser for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}soupsieve>=1.2:www/py-soupsieve@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.9\.

.include <bsd.port.mk>

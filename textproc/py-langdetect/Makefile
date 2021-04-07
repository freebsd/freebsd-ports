PORTNAME=	langdetect
PORTVERSION=	1.0.7
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Language detection library ported from Google\'s language-detection

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+ zip
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

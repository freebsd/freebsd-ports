PORTNAME=	dugong
PORTVERSION=	3.7.5
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	niklaas@kulturflatrate.net
COMMENT=	HTTP 1.1 client module designed for RESTful protocols
WWW=		https://github.com/python-dugong/python-dugong/

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python tar:bzip2
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	${PYTHON_CMD} -m pytest ${WRKSRC}/test

.include <bsd.port.mk>

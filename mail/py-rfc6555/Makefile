PORTNAME=	rfc6555
PORTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Happy Eyeballs Algorithm described in RFC 6555
WWW=		https://github.com/sethmlarson/rfc6555

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pytest python
# github port since tests are not included in sdist
# https://github.com/sethmlarson/rfc6555/pull/8
USE_GITHUB=	yes
GH_ACCOUNT=	sethmlarson
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

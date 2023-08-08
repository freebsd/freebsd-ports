PORTNAME=	twitter
PORTVERSION=	1.19.6
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-tools

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	API and command-line toolset for Twitter (twitter.com)
WWW=		https://github.com/sixohsix/twitter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	sixohsix
USE_PYTHON=	autoplist concurrent distutils nose

NO_ARCH=	yes

.include <bsd.port.mk>

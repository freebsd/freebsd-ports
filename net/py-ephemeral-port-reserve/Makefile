PORTNAME=	ephemeral-port-reserve
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
CATEGORIES=	net python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bind to ephemeral port, force TIME_WAIT state, and unbind it
WWW=		https://github.com/Yelp/ephemeral-port-reserve/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Yelp

NO_ARCH=	yes

.include <bsd.port.mk>

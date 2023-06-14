PORTNAME=	simplebayes
PORTVERSION=	1.5.8
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Memory-based, optional-persistence naive bayesian text classifier
WWW=		https://github.com/hickeroar/simplebayes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

post-extract: # https://github.com/hickeroar/simplebayes/issues/3
	@truncate -s 0 ${WRKSRC}/README.rst

.include <bsd.port.mk>

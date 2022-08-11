PORTNAME=	fraction
PORTVERSION=	2.2.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP \
		https://github.com/bradley101/fraction/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Fraction-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Carry out all the fraction operations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

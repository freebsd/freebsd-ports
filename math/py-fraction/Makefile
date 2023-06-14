PORTNAME=	fraction
PORTVERSION=	2.2.0
CATEGORIES=	math python
MASTER_SITES=	PYPI \
		https://github.com/bradley101/fraction/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Fraction-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Carry out all the fraction operations
WWW=		https://github.com/bradley101/fraction

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>

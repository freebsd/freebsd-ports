PORTNAME=	fraction
PORTVERSION=	2.2.0
PORTREVISION=	1
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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>

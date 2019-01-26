# $FreeBSD$

PORTNAME=		python-axolotl-curve25519
PORTVERSION=		0.4.1
DISTVERSIONSUFFIX=	.post2
CATEGORIES=		security python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Python wrapper for curve25519 with ed25519 signatures

LICENSE=	GPLv3

USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/axolotl_curve25519.so

.include <bsd.port.mk>

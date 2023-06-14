PORTNAME=		python-axolotl-curve25519
PORTVERSION=		0.4.1
DISTVERSIONSUFFIX=	.post2
CATEGORIES=		security python
MASTER_SITES=		PYPI
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Python wrapper for curve25519 with ed25519 signatures
WWW=		https://github.com/tgalal/python-axolotl-curve25519

LICENSE=	GPLv3

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/axolotl_curve25519*.so

.include <bsd.port.post.mk>

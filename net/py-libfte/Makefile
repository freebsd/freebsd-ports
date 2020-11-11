# $FreeBSD$

PORTNAME=	libfte
PORTVERSION=	0.1.3
CATEGORIES=	net security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fte-${PORTVERSION}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Format-Transforming Encryption Library/Toolkit

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-12-12

BUILD_DEPENDS=	regex2dfa:textproc/regex2dfa \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6.1:security/py-pycrypto@${PY_FLAVOR}
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		localbase python:2.7
USE_PYTHON=	autoplist distutils

# setup.cfg enables inplace, copying extension to final place and breaking
# autoplist
post-extract:
	${RM} ${WRKSRC}/setup.cfg

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/fte/cDFA.so

.include <bsd.port.mk>

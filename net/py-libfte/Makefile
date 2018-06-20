# $FreeBSD$

PORTNAME=	libfte
DISTVERSION=	0.1.0
CATEGORIES=	net security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@googlemail.com
COMMENT=	Format-Transforming Encryption Library/Toolkit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	regex2dfa:textproc/regex2dfa \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6.1:security/py-pycrypto@${PY_FLAVOR}
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		localbase python:2.7
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	kpdyer

# setup.cfg enables inplace, copying extension to final place and breaking
# autoplist
post-extract:
	${RM} ${WRKSRC}/setup.cfg

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/fte/cDFA.so

.include <bsd.port.mk>

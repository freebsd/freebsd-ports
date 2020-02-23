# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for cracklib

LICENSE=	LGPL21

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	libcrack.so:security/cracklib

MASTERDIR=	${.CURDIR}/../cracklib
PLIST=		${.CURDIR}/pkg-plist
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PYTHON_SLAVEPORT=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		"{s#__version__ = '[^']*'#__version__ = '${PORTVERSION}'#;}" \
		${BUILD_WRKSRC}/*.py

.include "${MASTERDIR}/Makefile"

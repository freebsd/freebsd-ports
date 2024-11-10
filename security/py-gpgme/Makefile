PORTREVISION=	0
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Gpgme Python bindings

MASTERDIR=	${.CURDIR:H:H}/security/gpgme
PLIST=		${.CURDIR}/pkg-plist

_GPGME_BINDING=	python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gpg/_gpgme*.so

.include "${MASTERDIR}/Makefile"

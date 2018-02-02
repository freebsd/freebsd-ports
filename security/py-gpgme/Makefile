# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Gpgme Python bindings

MASTERDIR=	${.CURDIR}/../../security/gpgme
SLAVEPORT=	python
BINDING_NAME=	python
PLIST=		${.CURDIR}/pkg-plist

.if ${FLAVOR:Upy27:Mpy2*}
CONFIGURE_ARGS+=--enable-languages="python2"
.else
CONFIGURE_ARGS+=--enable-languages="python3"
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}/site-packages/gpg/_gpgme.so

.include "${MASTERDIR}/Makefile"

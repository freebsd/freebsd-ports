# Created by: nbm
# $FreeBSD$

PORTNAME=	pycrypto
PORTVERSION=	2.6.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	The Python Cryptography Toolkit

USES=		python
USE_PYTHON=	distutils autoplist

HAS_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf

OPTIONS_DEFINE=		GMP
OPTIONS_DEFAULT=	GMP

GMP_DESC=		Use GMP for faster DSA/RSA operations

GMP_CONFIGURE_WITH=	gmp
GMP_CPPFLAGS=		-I${LOCALBASE}/include
GMP_LDFLAGS=		-L${LOCALBASE}/lib
GMP_LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

pre-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/setup.py

regression-test: build
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>

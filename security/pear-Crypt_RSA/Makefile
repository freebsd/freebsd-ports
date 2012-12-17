# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	Crypt_RSA
PORTVERSION=	1.2.1
CATEGORIES=	security www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class allows you to use two-key strong cryptography

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

OPTIONS_DEFINE=	BCMATH GMP
BCMATH_DESC=	PHP BCMath extension support
GMP_DESC=	PHP GMP extension support

LATEST_LINK=	pear-${PORTNAME}

.include <bsd.port.options.mk>

.for opt in BCMATH GMP
.    if ${PORT_OPTIONS:M${opt}}
USE_PHP+=	${opt:L}
.    endif
.endfor

CATEGORY=	Crypt
FILES=		RSA.php RSA/ErrorHandler.php RSA/Key.php RSA/KeyPair.php \
		RSA/MathLoader.php RSA/Math/BCMath.php RSA/Math/BigInt.php \
		RSA/Math/GMP.php
DOCS=		CREDITS LICENSE Crypt_RSA.txt math_wrappers.txt
EXAMPLES=	web_interface.php
TESTS=		test1.php test2.php bench.php

post-extract:
	@${MV} ${WRKSRC}/CREDITS ${WRKSRC}/docs
	@${MV} ${WRKSRC}/LICENSE ${WRKSRC}/docs

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>

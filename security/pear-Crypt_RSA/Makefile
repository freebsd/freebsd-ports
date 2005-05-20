# Ports collection makefile for:  pear-Crypt_RSA
# Date created:			  12 May 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Crypt_RSA
PORTVERSION=	1.0.0
CATEGORIES=	security www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class allows you to use two-key strong cryptography

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	BCMATH "PHP BCMath extension support" off \
		GMP "PHP GMP extension support" off

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	pear-${PORTNAME}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

.for opt in BCMATH GMP
.    if defined(WITH_${opt})
USE_PHP+=	${opt:L}
.    endif
.endfor

CATEGORY=	Crypt
FILES=		RSA.php RSA/ErrorHandler.php RSA/Key.php RSA/KeyPair.php \
		RSA/MathLoader.php RSA/Math/BCMath.php RSA/Math/BigInt.php \
		RSA/Math/GMP.php
DOCS=		CREDITS LICENSE Crypt_RSA.txt math_wrappers.txt
EXAMPLES=	web_interface.php
TESTS=		test1.php test2.php

post-extract:
	@${MV} ${WRKSRC}/CREDITS ${WRKSRC}/docs
	@${MV} ${WRKSRC}/LICENSE ${WRKSRC}/docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>

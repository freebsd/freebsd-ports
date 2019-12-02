# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sleef
DISTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	SIMD Library for Evaluating Elementary Functions, vectorized libm

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	shibatch

CFLAGS_powerpc64=	-mpower8-vector

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
PLIST_SUB+=	NO_PPC64="@comment "
.else
PLIST_SUB+=	NO_PPC64=""
.endif

.include <bsd.port.mk>

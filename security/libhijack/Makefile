# $FreeBSD$

PORTNAME=	libhijack
PORTVERSION=	0.8.0
CATEGORIES=	security

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Runtime process infection made easy

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64 aarch64

MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SoldierX
GH_PROJECT=	libhijack
GH_TAGNAME=	9d187b5

LIBDIR?=	${PREFIX}/lib

USE_HARDENING=	pie relro

.include <bsd.port.mk>

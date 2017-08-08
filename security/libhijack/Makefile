# $FreeBSD$

PORTNAME=	libhijack
PORTVERSION=	0.7.0
CATEGORIES=	security

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Runtime process infection made easy

LICENSE=	BSD2CLAUSE

MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SoldierX
GH_PROJECT=	libhijack
GH_TAGNAME=	f75bd30

LIBDIR?=	${PREFIX}/lib

USE_HARDENING=	pie relro

.include <bsd.port.mk>

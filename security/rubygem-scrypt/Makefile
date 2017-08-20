# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scrypt
PORTVERSION=	3.0.5
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Scrypt key derivation function

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	invokes SSE compiler flags

RUN_DEPENDS=	rubygem-ffi-compiler>=1.0:devel/rubygem-ffi-compiler

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

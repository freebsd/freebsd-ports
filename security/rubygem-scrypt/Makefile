# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scrypt
PORTVERSION=	2.1.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Scrypt key derivation function

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-ffi-compiler>=0.0.2:devel/rubygem-ffi-compiler \
		rubygem-rake>=0:devel/rubygem-rake

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	invokes SSE compiler flags

.include <bsd.port.mk>

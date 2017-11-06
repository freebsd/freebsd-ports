# $FreeBSD$

PORTNAME=	libilbc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet Low Bit Rate codec (RFC3951)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	not yet ported to this architecture

CONFLICTS=	ilbc-r[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	TimothyGu

USES=		cmake pathfix
USE_LDCONFIG=	yes

.include <bsd.port.mk>

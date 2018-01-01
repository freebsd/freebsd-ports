# $FreeBSD$

PORTNAME=	webpush
PORTVERSION=	0.3.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Encryption utilities for Web Push payload

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-hkdf>=0.2:security/rubygem-hkdf \
		rubygem-jwt>=2.0:www/rubygem-jwt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

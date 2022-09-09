PORTNAME=	webpush
PORTVERSION=	1.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Encryption utilities for Web Push payload
WWW=		https://github.com/zaru/webpush

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-hkdf0>=0.2<1:security/rubygem-hkdf0 \
		rubygem-jwt>=2.0<3:www/rubygem-jwt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

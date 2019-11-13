# $FreeBSD$

PORTNAME=	json-jwt
PORTVERSION=	1.11.0
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport50>=4.2:devel/rubygem-activesupport50 \
		rubygem-aes_key_wrap>=0:security/rubygem-aes_key_wrap \
		rubygem-bindata>=0:devel/rubygem-bindata

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

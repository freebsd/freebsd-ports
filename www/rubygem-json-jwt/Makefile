# $FreeBSD$

PORTNAME=	json-jwt
PORTVERSION=	1.9.3
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=0:devel/rubygem-activesupport4 \
		rubygem-aes_key_wrap>=0:security/rubygem-aes_key_wrap \
		rubygem-bindata>=0:devel/rubygem-bindata \
		rubygem-securecompare>=0:security/rubygem-securecompare

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

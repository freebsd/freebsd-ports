PORTNAME=	jwt
PORTVERSION=	2.9.3
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	29

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in Ruby
WWW=		https://github.com/jwt/ruby-jwt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.9\.

.include <bsd.port.mk>

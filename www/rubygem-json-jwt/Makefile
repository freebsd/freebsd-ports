PORTNAME=	json-jwt
PORTVERSION=	1.17.0
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in Ruby
WWW=		https://github.com/nov/json-jwt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport60>=4.2:devel/rubygem-activesupport60 \
		rubygem-aes_key_wrap>=0:security/rubygem-aes_key_wrap \
		rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-bindata>=0:devel/rubygem-bindata \
		rubygem-faraday>=2.0<3:www/rubygem-faraday \
		rubygem-faraday-follow_redirects>=0:www/rubygem-faraday-follow_redirects

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

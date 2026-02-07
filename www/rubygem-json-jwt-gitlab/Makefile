PORTNAME=	json-jwt
PORTVERSION=	1.16.7
PORTREVISION=	1
CATEGORIES=	www devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	JSON Web Token implementation in Ruby
WWW=		https://github.com/nov/json-jwt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=4.2:devel/rubygem-activesupport-gitlab \
		rubygem-aes_key_wrap>=0:security/rubygem-aes_key_wrap \
		rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-bindata>=0:devel/rubygem-bindata \
		rubygem-faraday-gitlab>=2.0<3:www/rubygem-faraday-gitlab \
		rubygem-faraday-follow_redirects-gitlab>=0:www/rubygem-faraday-follow_redirects-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

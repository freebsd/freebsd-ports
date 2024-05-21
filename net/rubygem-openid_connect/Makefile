PORTNAME=	openid_connect
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect Server & Client Library
WWW=		https://github.com/nov/openid_connect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel70>=0:databases/rubygem-activemodel70 \
		rubygem-attr_required>=1.0.0:devel/rubygem-attr_required \
		rubygem-json-jwt115>=1.5.0:www/rubygem-json-jwt115 \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp \
		rubygem-rack-oauth21>=1.6.1:security/rubygem-rack-oauth21 \
		rubygem-swd>=1.0.0:www/rubygem-swd \
		rubygem-tzinfo>=0:devel/rubygem-tzinfo \
		rubygem-validate_email>=0:devel/rubygem-validate_email \
		rubygem-validate_url>=0:devel/rubygem-validate_url \
		rubygem-webfinger>=1.0.1:devel/rubygem-webfinger

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

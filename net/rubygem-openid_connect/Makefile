PORTNAME=	openid_connect
PORTVERSION=	2.3.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect Server & Client Library
WWW=		https://github.com/nov/openid_connect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel70>=0:databases/rubygem-activemodel70 \
		rubygem-attr_required>=1.0.0:devel/rubygem-attr_required \
		rubygem-email_validator>=0:mail/rubygem-email_validator \
		rubygem-faraday>=2.0<3:www/rubygem-faraday \
		rubygem-faraday-follow_redirects>=0:www/rubygem-faraday-follow_redirects \
		rubygem-json-jwt>=1.16:www/rubygem-json-jwt \
		rubygem-mail>=0:mail/rubygem-mail \
		rubygem-rack-oauth2>=2.2<3:security/rubygem-rack-oauth2 \
		rubygem-swd>=2.0<3:www/rubygem-swd \
		rubygem-tzinfo>=0:devel/rubygem-tzinfo \
		rubygem-validate_url>=0:devel/rubygem-validate_url \
		rubygem-webfinger>=2.0<3:devel/rubygem-webfinger

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

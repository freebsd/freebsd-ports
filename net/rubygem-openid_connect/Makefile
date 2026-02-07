PORTNAME=	openid_connect
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect Server & Client Library
WWW=		https://github.com/nov/openid_connect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel-gitlab>=0:databases/rubygem-activemodel-gitlab \
		rubygem-attr_required>=1.0.0:devel/rubygem-attr_required \
		rubygem-email_validator>=0:mail/rubygem-email_validator \
		rubygem-faraday-gitlab>=2.0<3:www/rubygem-faraday-gitlab \
		rubygem-faraday-follow_redirects-gitlab>=0:www/rubygem-faraday-follow_redirects-gitlab \
		rubygem-json-jwt-gitlab>=1.16:www/rubygem-json-jwt-gitlab \
		rubygem-mail>=0:mail/rubygem-mail \
		rubygem-rack-oauth2-gitlab>=2.2<3:security/rubygem-rack-oauth2-gitlab \
		rubygem-swd>=2.0<3:www/rubygem-swd \
		rubygem-tzinfo>=0:devel/rubygem-tzinfo \
		rubygem-validate_url>=0:devel/rubygem-validate_url \
		rubygem-webfinger>=2.0<3:devel/rubygem-webfinger

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

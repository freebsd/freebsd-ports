PORTNAME=	oauth
PORTVERSION=	1.1.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rubygem for Creating both OAuth Consumers and Service Providers
WWW=		https://oauth.galtzo.com/ \
		https://github.com/ruby-oauth/oauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-auth-sanitizer>=0.1.2<1:security/rubygem-auth-sanitizer \
		rubygem-base64>=0.1<1:converters/rubygem-base64 \
		rubygem-cgi>=0:www/rubygem-cgi \
		rubygem-oauth-tty>=1.0.7<2:net/rubygem-oauth-tty \
		rubygem-snaky_hash>=2.0.4<3:devel/rubygem-snaky_hash \
		rubygem-version_gem>=1.1.9<2:devel/rubygem-version_gem

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

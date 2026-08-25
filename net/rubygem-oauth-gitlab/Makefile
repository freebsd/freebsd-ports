PORTNAME=	oauth
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Rubygem for Creating both OAuth Consumers and Service Providers
WWW=		https://oauth.galtzo.com/ \
		https://github.com/ruby-oauth/oauth

LICENSE=	MIT
#LICENSE_FILE=	${WRKSRC}/MIT.md

RUN_DEPENDS=	rubygem-auth-sanitizer-gitlab>=0.2.1<1:security/rubygem-auth-sanitizer-gitlab \
		rubygem-base64>=0.1<1:converters/rubygem-base64 \
		rubygem-oauth-tty-gitlab>=1.0.10<2:net/rubygem-oauth-tty-gitlab \
		rubygem-snaky_hash-gitlab>=2.0.5<3:devel/rubygem-snaky_hash-gitlab \
		rubygem-version_gem>=1.1.12<2:devel/rubygem-version_gem

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

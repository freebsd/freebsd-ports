PORTNAME=	oauth
PORTVERSION=	1.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rubygem for Creating both OAuth Consumers and Service Providers
WWW=		https://gitlab.com/oauth-xx/oauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-oauth-tty>=1.0.1<2:net/rubygem-oauth-tty \
		rubygem-snaky_hash>=2.0<3:devel/rubygem-snaky_hash \
		rubygem-version_gem>=1.1<2:devel/rubygem-version_gem

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

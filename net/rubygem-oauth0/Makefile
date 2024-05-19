PORTNAME=	oauth
PORTVERSION=	0.5.14
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rubygem for Creating both OAuth Consumers and Service Providers
WWW=		https://github.com/oauth-xx/oauth-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/oauth

.include <bsd.port.mk>

PORTNAME=	az-identity
PORTVERSION=	0.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Credential acquisition for Azure services
WWW=		https://gitlab.com/gitlab-org/ruby/gems/az-identity

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-faraday-gitlab>=2.0<3:www/rubygem-faraday-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

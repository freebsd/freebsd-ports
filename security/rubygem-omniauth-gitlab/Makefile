PORTNAME=	omniauth-gitlab
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth strategy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-omniauth1>=1.0<2:security/rubygem-omniauth1 \
		rubygem-omniauth-oauth2>=1.0<2:net/rubygem-omniauth-oauth2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

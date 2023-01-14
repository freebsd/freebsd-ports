PORTNAME=	omniauth-gitlab
PORTVERSION=	4.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth strategy for GitLab
WWW=		https://github.com/linchus/omniauth-gitlab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-omniauth>=2.0<3:security/rubygem-omniauth \
		rubygem-omniauth-oauth2>=1.8.0<1.9:net/rubygem-omniauth-oauth2

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

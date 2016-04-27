# $FreeBSD$

PORTNAME=	omniauth-gitlab
PORTVERSION=	1.0.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth strategy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-omniauth>=1.0:security/rubygem-omniauth \
		rubygem-omniauth-oauth2>=1.0:net/rubygem-omniauth-oauth2

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

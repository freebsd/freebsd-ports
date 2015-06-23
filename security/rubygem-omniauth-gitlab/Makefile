# $FreeBSD$

PORTNAME=	omniauth-gitlab
PORTVERSION=	1.0.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OmniAuth strategy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-omniauth>=1.0:${PORTSDIR}/security/rubygem-omniauth \
		rubygem-omniauth-oauth2>=1.0:${PORTSDIR}/net/rubygem-omniauth-oauth2

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>

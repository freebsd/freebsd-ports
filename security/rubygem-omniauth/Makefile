# $FreeBSD$

PORTNAME=	omniauth
PORTVERSION=	1.9.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generalized Rack framework for multiple-provider authentication

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-hashie>=3.4.6:devel/rubygem-hashie \
		rubygem-rack>=1.6.2,3<3,3:www/rubygem-rack

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

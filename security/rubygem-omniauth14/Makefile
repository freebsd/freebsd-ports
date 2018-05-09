# $FreeBSD$

PORTNAME=	omniauth
PORTVERSION=	1.4.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	14

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Generalized Rack framework for multiple-provider authentication

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-hashie>=3.4.6:devel/rubygem-hashie \
		rubygem-rack>=1.6.2:www/rubygem-rack

PORTSCOUT=	limit:^1\.4

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>

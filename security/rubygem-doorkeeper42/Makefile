# $FreeBSD$

PORTNAME=	doorkeeper
PORTVERSION=	4.2.6
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	42

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Doorkeeper is an OAuth 2 provider for Rails and Grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties4>=4.2:www/rubygem-railties4

PORTSCOUT=	limit:^4\.2\.

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>

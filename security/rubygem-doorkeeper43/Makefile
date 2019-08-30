# $FreeBSD$

PORTNAME=	doorkeeper
PORTVERSION=	4.3.2
PORTREVISION=	3
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	43

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Doorkeeper is an OAuth 2 provider for Rails and Grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties52>=4.2:www/rubygem-railties52

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.3\.

.include <bsd.port.mk>

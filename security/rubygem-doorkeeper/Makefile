# $FreeBSD$

PORTNAME=	doorkeeper
PORTVERSION=	3.1.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Doorkeeper is an OAuth 2 provider for Rails and Grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

OPTIONS_SINGLE=	SG1
OPTIONS_SINGLE_SG1=	RAILTIES RAILTIES4

RAILTIES_DESC=	Use Railties 3
RAILTIES4_DESC=	Use Railties 4

OPTIONS_DEFAULT=	RAILTIES4

RAILTIES_RUN_DEPENDS=	rubygem-railties>=3.2:www/rubygem-railties
RAILTIES4_RUN_DEPENDS=	rubygem-railties4>=4.0:www/rubygem-railties4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

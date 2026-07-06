PORTNAME=	doorkeeper
PORTVERSION=	5.9.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OAuth2 provider for Rails and Grape
WWW=		https://github.com/doorkeeper-gem/doorkeeper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties-gitlab>=5:www/rubygem-railties-gitlab

USES=		cpe gem

CPE_VENDOR=	doorkeeper_project

NO_ARCH=	yes

.include <bsd.port.mk>

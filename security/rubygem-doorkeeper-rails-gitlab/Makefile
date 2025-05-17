PORTNAME=	doorkeeper
PORTVERSION=	5.8.2
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

NO_ARCH=	yes

CPE_VENDOR=	doorkeeper_project

.include <bsd.port.mk>

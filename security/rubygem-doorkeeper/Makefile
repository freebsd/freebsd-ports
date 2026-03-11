PORTNAME=	doorkeeper
PORTVERSION=	5.8.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX?=	# empty for base port

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OAuth2 provider for Rails and Grape
WWW=		https://github.com/doorkeeper-gem/doorkeeper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

# Default to Rails 6.1 for the base port, can be overridden by slave ports
RAILS_VERSION?=	61
RUN_DEPENDS=	rubygem-railties${RAILS_VERSION}>=5:www/rubygem-railties${RAILS_VERSION}

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	doorkeeper_project

.include <bsd.port.mk>

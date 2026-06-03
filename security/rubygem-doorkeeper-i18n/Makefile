PORTNAME=	doorkeeper-i18n
PORTVERSION=	5.2.8
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX?=	# empty for base port

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Internationalization files for Doorkeeper OAuth2 provider
WWW=		https://github.com/doorkeeper-gem/doorkeeper-i18n

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

# Default to base doorkeeper for the base port, can be overridden by slave ports
RAILS_VERSION?=	# empty for base port
.if empty(RAILS_VERSION)
RUN_DEPENDS=	rubygem-doorkeeper>=4.0:security/rubygem-doorkeeper
.else
RUN_DEPENDS=	rubygem-doorkeeper-rails${RAILS_VERSION}>=4.0:security/rubygem-doorkeeper-rails${RAILS_VERSION}
.endif

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

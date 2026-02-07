PORTNAME=	requestjs-rails
PORTVERSION=	0.0.14
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX?=	# empty for base port

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tiny Fetch API wrapper for Rails with CSRF token handling
WWW=		https://github.com/marcelolx/requestjs-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

# Default to Rails 7.1 for the base port, can be overridden by slave ports
RAILS_VERSION?=	71
RUN_DEPENDS=	rubygem-railties${RAILS_VERSION}>=7.1.0:www/rubygem-railties${RAILS_VERSION}

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

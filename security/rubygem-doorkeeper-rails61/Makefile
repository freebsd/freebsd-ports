PORTNAME=	doorkeeper
DISTVERSION=	5.7.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	OAuth2 provider for Rails and Grape
WWW=		https://github.com/doorkeeper-gem/doorkeeper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

DEPRECATED=	Ruby on Rails 6.1.x reaches EOL on 2024-10-01
EXPIRATION_DATE=	2024-10-24

RUN_DEPENDS=	rubygem-railties61>=5:www/rubygem-railties61

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	doorkeeper_project

.include <bsd.port.mk>

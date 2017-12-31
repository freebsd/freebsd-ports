# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webpack-rails
PORTVERSION=	0.9.11
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JavaScript-first tooling to use webpack within your Rails application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties4>=3.2.0:www/rubygem-railties4

# www/gitlab still depends on this port
DEPRECATED=	Upstream no longer maintained, use devel/rubygem-webpacker-rails* instead
EXPIRATION_DATE=2018-01-31

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

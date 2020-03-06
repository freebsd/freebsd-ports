# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webpack-rails
PORTVERSION=	0.9.11
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	JavaScript-first tooling to use webpack within your Rails application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties60>=3.2.0:www/rubygem-railties60

# www/gitlab-ce still depends on this port
DEPRECATED=	Upstream no longer maintained, use devel/rubygem-webpacker-rails* instead
EXPIRATION_DATE=2020-12-31

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

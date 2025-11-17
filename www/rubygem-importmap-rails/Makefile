PORTNAME=	importmap-rails
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use ESM with importmap to manage modern JavaScript in Rails without transpiling or bundling
WWW=		https://github.com/rails/importmap-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack81>=6.0.0:www/rubygem-actionpack81 \
		rubygem-activesupport81>=6.0.0:devel/rubygem-activesupport81 \
		rubygem-railties81>=6.0.0:www/rubygem-railties81

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

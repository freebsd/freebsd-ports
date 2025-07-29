PORTNAME=	importmap-rails
PORTVERSION=	2.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use ESM with importmap to manage modern JavaScript in Rails without transpiling or bundling
WWW=		https://github.com/rails/importmap-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack71>=6.0.0:www/rubygem-actionpack71 \
		rubygem-activesupport71>=6.0.0:devel/rubygem-activesupport71 \
		rubygem-railties71>=6.0.0:www/rubygem-railties71

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

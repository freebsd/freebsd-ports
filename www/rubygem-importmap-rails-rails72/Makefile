PORTNAME=	importmap-rails
PORTVERSION=	2.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use ESM with importmap to manage modern JavaScript in Rails without transpiling or bundling
WWW=		https://github.com/rails/importmap-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack72>=6.0.0:www/rubygem-actionpack72 \
		rubygem-activesupport72>=6.0.0:devel/rubygem-activesupport72 \
		rubygem-railties72>=6.0.0:www/rubygem-railties72

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

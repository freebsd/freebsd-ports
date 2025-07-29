PORTNAME=	importmap-rails
PORTVERSION=	2.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use ESM with importmap to manage modern JavaScript in Rails without transpiling or bundling
WWW=		https://github.com/rails/importmap-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack80>=6.0.0:www/rubygem-actionpack80 \
		rubygem-activesupport80>=6.0.0:devel/rubygem-activesupport80 \
		rubygem-railties80>=6.0.0:www/rubygem-railties80

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

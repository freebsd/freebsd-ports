PORTNAME=	importmap-rails
PORTVERSION=	2.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use ESM with importmap to manage modern JavaScript in Rails without transpiling or bundling
WWW=		https://github.com/rails/importmap-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=6.0.0:www/rubygem-actionpack70 \
		rubygem-activesupport70>=6.0.0:devel/rubygem-activesupport70 \
		rubygem-railties70>=6.0.0:www/rubygem-railties70

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

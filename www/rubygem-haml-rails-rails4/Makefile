PORTNAME=	haml-rails
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Haml generator for Rails
WWW=		https://github.com/indirect/haml-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack4>=4.0.1:www/rubygem-actionpack4 \
		rubygem-activesupport4>=4.0.1:devel/rubygem-activesupport4 \
		rubygem-haml5>=4.0.6<6.0:www/rubygem-haml5 \
		rubygem-html2haml>=1.0.1:www/rubygem-html2haml \
		rubygem-railties4>=4.0.1:www/rubygem-railties4

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

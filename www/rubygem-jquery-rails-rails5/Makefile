PORTNAME=	jquery-rails
PORTVERSION=	4.5.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides a Rails generator for jQuery

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rails-dom-testing-rails5>=1<3:textproc/rubygem-rails-dom-testing-rails5 \
		rubygem-railties5>=4.2.0:www/rubygem-railties5 \
		rubygem-thor>=0.14<2.0:devel/rubygem-thor

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails

.include <bsd.port.mk>

PORTNAME=	jquery-rails
PORTVERSION=	4.6.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides a Rails generator for jQuery
WWW=		https://github.com/rails/jquery-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rails-dom-testing-rails50>=1<3:textproc/rubygem-rails-dom-testing-rails50 \
		rubygem-railties50>=4.2.0:www/rubygem-railties50 \
		rubygem-thor>=0.14<2.0:devel/rubygem-thor

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails

.include <bsd.port.mk>

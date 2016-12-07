# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	3.2.22.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MVC web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionmailer>=${PORTVERSION}:mail/rubygem-actionmailer \
		rubygem-actionpack>=${PORTVERSION}:www/rubygem-actionpack \
		rubygem-activerecord>=${PORTVERSION}:databases/rubygem-activerecord \
		rubygem-activeresource>=${PORTVERSION}:www/rubygem-activeresource \
		rubygem-activesupport>=${PORTVERSION}:devel/rubygem-activesupport \
		rubygem-bundler>=1.0:sysutils/rubygem-bundler \
		rubygem-railties>=${PORTVERSION}:www/rubygem-railties \
		rubygem-builder>=3.0.4:devel/rubygem-builder \
		rubygem-coffee-rails>=3.2.2:devel/rubygem-coffee-rails \
		rubygem-i18n>=0.6.1:devel/rubygem-i18n \
		rubygem-jquery-rails>=3.1.0:www/rubygem-jquery-rails \
		rubygem-json>=1.7.6:devel/rubygem-json \
		rubygem-sprockets22>=2.2.2:devel/rubygem-sprockets22 \
		rubygem-rack14>=1.4.4:www/rubygem-rack14 \
		rubygem-rdoc3>=3.4:devel/rubygem-rdoc3 \
		rubygem-rack-test>=0.6.1:www/rubygem-rack-test \
		rubygem-rake>=10.1.1:devel/rubygem-rake \
		rubygem-sass-rails>=3.2.6:textproc/rubygem-sass-rails \
		rubygem-sqlite3>=1.3.9:databases/rubygem-sqlite3 \
		rubygem-treetop>=1.4.15:devel/rubygem-treetop \
		rubygem-turn>=0.8.3:devel/rubygem-turn \
		rubygem-tzinfo03>=0.3.39:devel/rubygem-tzinfo03 \
		rubygem-uglifier>=2.5.0:www/rubygem-uglifier

# XXX: rails3 gem no longer has a lib/ dir
# XXX: which breaks devel/ruby-gems specification.
# XXX: and thus rdoc
NOPORTDOCS=	yes

NO_ARCH=	yes
USE_RUBY=	yes
USES=		cpe gem

PLIST_DIRS=	${GEM_LIB_DIR}

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

DEPRECATED=	Upstream support ended
EXPIRATION_DATE=	2017-01-07

OPTIONS_DEFINE=	PASSENGER MEMCACHE_CLIENT
PASSENGER_DESC=	Passenger backend
MEMCACHE_CLIENT_DESC=	MemCache-Client support

MEMCACHE_CLIENT_RUN_DEPENDS=	rubygem-memcache-client>=1.2.0:databases/rubygem-memcache-client
PASSENGER_RUN_DEPENDS=	rubygem-passenger>=2.2.15:www/rubygem-passenger

.include <bsd.port.mk>

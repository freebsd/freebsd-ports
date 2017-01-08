# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	4.2.7.1
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	MVC web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionmailer4>=${PORTVERSION}:mail/rubygem-actionmailer4 \
		rubygem-actionpack4>=${PORTVERSION}:www/rubygem-actionpack4 \
		rubygem-actionview4>=${PORTVERSION}:devel/rubygem-actionview4 \
		rubygem-activejob>=${PORTVERSION}:devel/rubygem-activejob \
		rubygem-activemodel4>=${PORTVERSION}:databases/rubygem-activemodel4 \
		rubygem-activerecord4>=${PORTVERSION}:databases/rubygem-activerecord4 \
		rubygem-activeresource4>=4.0.0:www/rubygem-activeresource4 \
		rubygem-activesupport4>=${PORTVERSION}:devel/rubygem-activesupport4 \
		rubygem-builder32>=3.2.2:devel/rubygem-builder32 \
		rubygem-bundler>=1.3.0:sysutils/rubygem-bundler \
		rubygem-byebug>=5.0.0:devel/rubygem-byebug \
		rubygem-coffee-rails41>=4.1.1:devel/rubygem-coffee-rails41 \
		rubygem-execjs>=2.2.1:devel/rubygem-execjs \
		rubygem-jbuilder>=2.1.3:devel/rubygem-jbuilder \
		rubygem-jquery-rails4>=4.0:www/rubygem-jquery-rails4 \
		rubygem-railties4>=${PORTVERSION}:www/rubygem-railties4 \
		rubygem-rake>=10.3:devel/rubygem-rake \
		rubygem-rdoc>=4.0.2:devel/rubygem-rdoc \
		rubygem-sass>=3.4.1:textproc/rubygem-sass \
		rubygem-sass-rails5>=5.0.3:textproc/rubygem-sass-rails5 \
		rubygem-sdoc>=0.4.1:devel/rubygem-sdoc \
		rubygem-spring>=1.1.3:devel/rubygem-spring \
		rubygem-sqlite3>=1.3.9:databases/rubygem-sqlite3 \
		rubygem-sprockets3>=3.0.3:devel/rubygem-sprockets3 \
		rubygem-sprockets-rails>=2.0:devel/rubygem-sprockets-rails \
		rubygem-thread_safe>=0.3.4:devel/rubygem-thread_safe \
		rubygem-turbolinks>=2.3.0:www/rubygem-turbolinks \
		rubygem-uglifier>=2.5.0:www/rubygem-uglifier \
		rubygem-web-console2>=2.1.2:devel/rubygem-web-console2

NO_ARCH=	yes
USE_RUBY=	yes
USES=		cpe gem

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

OPTIONS_DEFINE=	PASSENGER MEMCACHE_CLIENT
PASSENGER_DESC=	Passenger backend
MEMCACHE_CLIENT_DESC=	MemCache-Client support

MEMCACHE_CLIENT_RUN_DEPENDS=	rubygem-memcache-client>=1.2.0:databases/rubygem-memcache-client
PASSENGER_RUN_DEPENDS=	rubygem-passenger>=2.2.15:www/rubygem-passenger

.include <bsd.port.mk>

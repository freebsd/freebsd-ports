# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	5.0.6
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Full-stack web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actioncable50>=${PORTVERSION}:www/rubygem-actioncable50 \
		rubygem-actionmailer50>=${PORTVERSION}:mail/rubygem-actionmailer50 \
		rubygem-actionpack50>=${PORTVERSION}:www/rubygem-actionpack50 \
		rubygem-actionview50>=${PORTVERSION}:devel/rubygem-actionview50 \
		rubygem-activejob50>=${PORTVERSION}:devel/rubygem-activejob50 \
		rubygem-activemodel50>=${PORTVERSION}:databases/rubygem-activemodel50 \
		rubygem-activerecord50>=${PORTVERSION}:databases/rubygem-activerecord50 \
		rubygem-activesupport50>=${PORTVERSION}:devel/rubygem-activesupport50 \
		rubygem-bundler<2.0:sysutils/rubygem-bundler \
		rubygem-railties50>=${PORTVERSION}:www/rubygem-railties50 \
		rubygem-sprockets-rails-rails50>=2.0.0:devel/rubygem-sprockets-rails-rails50

 RUN_DEPENDS+=	rubygem-bindex>=0.5.0:devel/rubygem-bindex \
		rubygem-byebug>=9.0.6:devel/rubygem-byebug \
		rubygem-coffee-rails-rails50>=4.2.1:devel/rubygem-coffee-rails-rails50 \
		rubygem-coffee-script-source>=1.12.2:devel/rubygem-coffee-script-source \
		rubygem-coffee-script>=2.4.1:devel/rubygem-coffee-script \
		rubygem-execjs>=2.7.0:devel/rubygem-execjs \
		rubygem-ffi>=1.9.18:devel/rubygem-ffi \
		rubygem-jbuilder-rails50>=2.6.3:devel/rubygem-jbuilder-rails50 \
		rubygem-jquery-rails-rails50>=4.3.1:www/rubygem-jquery-rails-rails50 \
		rubygem-multi_json>=1.12.1:devel/rubygem-multi_json \
		rubygem-puma>=3.8.2:www/rubygem-puma \
		rubygem-rb-fsevent>=0.10.2:devel/rubygem-rb-fsevent \
		rubygem-rb-inotify>=0.9.10:devel/rubygem-rb-inotify \
		rubygem-sass-listen>=4.0.0:textproc/rubygem-sass-listen \
		rubygem-sass-rails-rails50>=5.0.3:textproc/rubygem-sass-rails-rails50 \
		rubygem-sass>=3.4.23:textproc/rubygem-sass \
		rubygem-spring-rails50>=2.0.1:devel/rubygem-spring-rails50 \
		rubygem-sqlite3>=1.3.13:databases/rubygem-sqlite3 \
		rubygem-tilt>=2.0.7:devel/rubygem-tilt \
		rubygem-turbolinks-source>=5.0.0:www/rubygem-turbolinks-source \
		rubygem-turbolinks-rails50>=5.0.1:www/rubygem-turbolinks-rails50 \
		rubygem-uglifier>=3.2.0:www/rubygem-uglifier \
		rubygem-web-console-rails50>=3.5.0:devel/rubygem-web-console-rails50

PORTSCOUT=	limit:^5\.0\.

NO_ARCH=	yes

USES=		gem
USE_RUBY=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

.include <bsd.port.mk>

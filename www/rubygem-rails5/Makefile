# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	5.1.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Full-stack web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actioncable5>=${PORTVERSION}:www/rubygem-actioncable5 \
		rubygem-actionmailer5>=${PORTVERSION}:mail/rubygem-actionmailer5 \
		rubygem-actionpack5>=${PORTVERSION}:www/rubygem-actionpack5 \
		rubygem-actionview5>=${PORTVERSION}:devel/rubygem-actionview5 \
		rubygem-activejob5>=${PORTVERSION}:devel/rubygem-activejob5 \
		rubygem-activemodel5>=${PORTVERSION}:databases/rubygem-activemodel5 \
		rubygem-activerecord5>=${PORTVERSION}:databases/rubygem-activerecord5 \
		rubygem-activesupport5>=${PORTVERSION}:devel/rubygem-activesupport5 \
		rubygem-bundler>=1.3.0:sysutils/rubygem-bundler \
		rubygem-railties5>=${PORTVERSION}:www/rubygem-railties5 \
		rubygem-sprockets-rails-rails5>=2.0.0:devel/rubygem-sprockets-rails-rails5 \
		rubygem-bindex>=0.5.0:devel/rubygem-bindex \
		rubygem-byebug>=9.0.6:devel/rubygem-byebug \
		rubygem-capybara>=2.14.0:devel/rubygem-capybara \
		rubygem-coffee-rails-rails5>=4.2.1:devel/rubygem-coffee-rails-rails5 \
		rubygem-coffee-script-source>=1.12.2:devel/rubygem-coffee-script-source \
		rubygem-coffee-script>=2.4.1:devel/rubygem-coffee-script \
		rubygem-execjs>=2.7.0:devel/rubygem-execjs \
		rubygem-jbuilder-rails5>=2.6.3:devel/rubygem-jbuilder-rails5 \
		rubygem-jquery-rails-rails5>=4.3.1:www/rubygem-jquery-rails-rails5 \
		rubygem-mini_mime>=0:mail/rubygem-mini_mime \
		rubygem-multi_json>=1.12.1:devel/rubygem-multi_json \
		rubygem-puma>=3.8.2:www/rubygem-puma \
		rubygem-rb-fsevent>=0.10.2:devel/rubygem-rb-fsevent \
		rubygem-rb-inotify>=0.9.10:devel/rubygem-rb-inotify \
		rubygem-sass-listen>=4.0.0:textproc/rubygem-sass-listen \
		rubygem-sass-rails-rails5>=5.0.3:textproc/rubygem-sass-rails-rails5 \
		rubygem-sass>=3.4.23:textproc/rubygem-sass \
		rubygem-selenium-webdriver>=3.4.0:www/rubygem-selenium-webdriver \
		rubygem-spring-rails5>=2.0.1:devel/rubygem-spring-rails5 \
		rubygem-sqlite3>=1.3.13:databases/rubygem-sqlite3 \
		rubygem-tilt>=2.0.7:devel/rubygem-tilt \
		rubygem-turbolinks-source>=5.0.0:www/rubygem-turbolinks-source \
		rubygem-turbolinks-rails5>=5.0.1:www/rubygem-turbolinks-rails5 \
		rubygem-uglifier>=3.2.0:www/rubygem-uglifier \
		rubygem-web-console>=3.5.0:devel/rubygem-web-console

NO_ARCH=	yes

USES=		gem
USE_RUBY=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

.include <bsd.port.mk>

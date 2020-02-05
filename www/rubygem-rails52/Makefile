# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	5.2.4.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-stack web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actioncable52>=${PORTVERSION}:www/rubygem-actioncable52 \
		rubygem-actionmailer52>=${PORTVERSION}:mail/rubygem-actionmailer52 \
		rubygem-actionpack52>=${PORTVERSION}:www/rubygem-actionpack52 \
		rubygem-actionview52>=${PORTVERSION}:devel/rubygem-actionview52 \
		rubygem-activejob52>=${PORTVERSION}:devel/rubygem-activejob52 \
		rubygem-activemodel52>=${PORTVERSION}:databases/rubygem-activemodel52 \
		rubygem-activerecord52>=${PORTVERSION}:databases/rubygem-activerecord52 \
		rubygem-activestorage52>=${PORTVERSION}:net/rubygem-activestorage52 \
		rubygem-activesupport52>=${PORTVERSION}:devel/rubygem-activesupport52 \
		rubygem-bundler>=1.3.0:sysutils/rubygem-bundler \
		rubygem-railties52>=${PORTVERSION}:www/rubygem-railties52 \
		rubygem-bootsnap>=1.1.0:devel/rubygem-bootsnap \
		rubygem-byebug>=0:devel/rubygem-byebug \
		rubygem-capybara>=2.15:devel/rubygem-capybara \
		rubygem-chromedriver-helper>=0:www/rubygem-chromedriver-helper \
		rubygem-coffee-rails-rails52>=0:devel/rubygem-coffee-rails-rails52 \
		rubygem-jbuilder-rails52>=0:devel/rubygem-jbuilder-rails52 \
		rubygem-mini_magick>=0:graphics/rubygem-mini_magick \
		rubygem-nokogiri>=1.8.1:textproc/rubygem-nokogiri \
		rubygem-puma>=0:www/rubygem-puma \
		rubygem-rake>=11.1:devel/rubygem-rake \
		rubygem-sass-rails-rails52>=0:textproc/rubygem-sass-rails-rails52 \
		rubygem-selenium-webdriver>=0:www/rubygem-selenium-webdriver \
		rubygem-spring>=0:devel/rubygem-spring \
		rubygem-sqlite3>=1.3.6:databases/rubygem-sqlite3 \
		rubygem-turbolinks>=5:www/rubygem-turbolinks \
		rubygem-uglifier>=1.3.0:www/rubygem-uglifier \
		rubygem-web-console3-rails52>=3.3.0:devel/rubygem-web-console3-rails52

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^5\.2\.

.include <bsd.port.mk>

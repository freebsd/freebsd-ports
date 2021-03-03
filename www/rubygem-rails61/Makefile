# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	rails
PORTVERSION=	6.1.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-stack web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actioncable61>=${PORTVERSION}:www/rubygem-actioncable61 \
		rubygem-actionmailbox61>=${PORTVERSION}:mail/rubygem-actionmailbox61 \
		rubygem-actionmailer61>=${PORTVERSION}:mail/rubygem-actionmailer61 \
		rubygem-actionpack61>=${PORTVERSION}:www/rubygem-actionpack61 \
		rubygem-actiontext61>=${PORTVERSION}:textproc/rubygem-actiontext61 \
		rubygem-actionview61>=${PORTVERSION}:devel/rubygem-actionview61 \
		rubygem-activejob61>=${PORTVERSION}:devel/rubygem-activejob61 \
		rubygem-activemodel61>=${PORTVERSION}:databases/rubygem-activemodel61 \
		rubygem-activerecord61>=${PORTVERSION}:databases/rubygem-activerecord61 \
		rubygem-activestorage61>=${PORTVERSION}:net/rubygem-activestorage61 \
		rubygem-activesupport61>=${PORTVERSION}:devel/rubygem-activesupport61 \
		rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-railties61>=${PORTVERSION}:www/rubygem-railties61 \
		rubygem-sprockets-rails-rails61>=2.0.0:devel/rubygem-sprockets-rails-rails61 \
		rubygem-bootsnap>=1.4.4:devel/rubygem-bootsnap \
		rubygem-byebug>=0:devel/rubygem-byebug \
		rubygem-capybara>=3.26:devel/rubygem-capybara \
		rubygem-dalli>=0:databases/rubygem-dalli \
		rubygem-image_processing>=1.2<2:graphics/rubygem-image_processing \
		rubygem-jbuilder-rails61>=0:devel/rubygem-jbuilder-rails61 \
		rubygem-nokogiri>=1.8.1:textproc/rubygem-nokogiri \
		rubygem-puma>=0:www/rubygem-puma \
		rubygem-rake>=11.1:devel/rubygem-rake \
		rubygem-sass-rails-rails61>=0:textproc/rubygem-sass-rails-rails61 \
		rubygem-selenium-webdriver>=3.141.5.92:www/rubygem-selenium-webdriver \
		rubygem-spring>=0:devel/rubygem-spring \
		rubygem-sqlite3>=1.4<2:databases/rubygem-sqlite3 \
		rubygem-turbolinks>=5<6:www/rubygem-turbolinks \
		rubygem-uglifier>=1.3.0:www/rubygem-uglifier \
		rubygem-web-console-rails61>=3.3.0:devel/rubygem-web-console-rails61 \
		rubygem-webdrivers>=0:www/rubygem-webdrivers \
		rubygem-webmock>=0:www/rubygem-webmock \
		rubygem-webpacker-rails61>=5.0<6:devel/rubygem-webpacker-rails61

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>

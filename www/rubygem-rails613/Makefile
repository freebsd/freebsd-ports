# Created by: Johannes Meixner <johannes@perceivon.net>

PORTNAME=	rails
PORTVERSION=	6.1.3.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	613

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Full-stack web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actioncable613>=${PORTVERSION}:www/rubygem-actioncable613 \
		rubygem-actionmailbox613>=${PORTVERSION}:mail/rubygem-actionmailbox613 \
		rubygem-actionmailer613>=${PORTVERSION}:mail/rubygem-actionmailer613 \
		rubygem-actionpack613>=${PORTVERSION}:www/rubygem-actionpack613 \
		rubygem-actiontext613>=${PORTVERSION}:textproc/rubygem-actiontext613 \
		rubygem-actionview613>=${PORTVERSION}:devel/rubygem-actionview613 \
		rubygem-activejob613>=${PORTVERSION}:devel/rubygem-activejob613 \
		rubygem-activemodel613>=${PORTVERSION}:databases/rubygem-activemodel613 \
		rubygem-activerecord613>=${PORTVERSION}:databases/rubygem-activerecord613 \
		rubygem-activestorage613>=${PORTVERSION}:net/rubygem-activestorage613 \
		rubygem-activesupport613>=${PORTVERSION}:devel/rubygem-activesupport613 \
		rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-railties613>=${PORTVERSION}:www/rubygem-railties613 \
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
		rubygem-sass-rails-rails613>=0:textproc/rubygem-sass-rails-rails613 \
		rubygem-selenium-webdriver>=3.141.5.92:www/rubygem-selenium-webdriver \
		rubygem-spring>=0:devel/rubygem-spring \
		rubygem-sqlite3>=1.4<2:databases/rubygem-sqlite3 \
		rubygem-turbolinks>=5<6:www/rubygem-turbolinks \
		rubygem-uglifier>=1.3.0:www/rubygem-uglifier \
		rubygem-web-console-rails613>=3.3.0:devel/rubygem-web-console-rails613 \
		rubygem-webdrivers>=0:www/rubygem-webdrivers \
		rubygem-webmock>=0:www/rubygem-webmock \
		rubygem-webpacker-rails613>=5.0<6:devel/rubygem-webpacker-rails613

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>

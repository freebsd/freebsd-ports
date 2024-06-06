PORTNAME=	rails
PORTVERSION=	6.1.7.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-stack web application framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actioncable61>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actioncable61 \
		rubygem-actionmailbox61>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailbox61 \
		rubygem-actionmailer61>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailer61 \
		rubygem-actionpack61>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack61 \
		rubygem-actiontext61>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-actiontext61 \
		rubygem-actionview61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview61 \
		rubygem-activejob61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob61 \
		rubygem-activemodel61>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel61 \
		rubygem-activerecord61>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord61 \
		rubygem-activestorage61>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage61 \
		rubygem-activesupport61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport61 \
		rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-railties61>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-railties61 \
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
		rubygem-selenium-webdriver>=4.11.0:www/rubygem-selenium-webdriver \
		rubygem-spring>=0:devel/rubygem-spring \
		rubygem-sqlite3>=1.4:databases/rubygem-sqlite3 \
		rubygem-turbolinks>=5<6:www/rubygem-turbolinks \
		rubygem-uglifier>=1.3.0:www/rubygem-uglifier \
		rubygem-web-console-rails61>=3.3.0:devel/rubygem-web-console-rails61 \
		rubygem-webmock>=0:www/rubygem-webmock \
		rubygem-webpacker-rails61>=5.0<6:devel/rubygem-webpacker-rails61 \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>

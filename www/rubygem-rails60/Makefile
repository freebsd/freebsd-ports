PORTNAME=	rails
PORTVERSION=	6.0.6.1
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-stack web application framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actioncable60>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actioncable60 \
		rubygem-actionmailbox60>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailbox60 \
		rubygem-actionmailer60>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailer60 \
		rubygem-actionpack60>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack60 \
		rubygem-actiontext60>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-actiontext60 \
		rubygem-actionview60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview60 \
		rubygem-activejob60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob60 \
		rubygem-activemodel60>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel60 \
		rubygem-activerecord60>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord60 \
		rubygem-activestorage60>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage60 \
		rubygem-activesupport60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport60 \
		rubygem-bundler>=1.3.0:sysutils/rubygem-bundler \
		rubygem-railties60>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-railties60 \
		rubygem-sprockets-rails-rails60>=2.0.0:devel/rubygem-sprockets-rails-rails60 \
		rubygem-bootsnap>=1.4.2:devel/rubygem-bootsnap \
		rubygem-byebug>=0:devel/rubygem-byebug \
		rubygem-capybara>=2.15:devel/rubygem-capybara \
		rubygem-dalli>=0:databases/rubygem-dalli \
		rubygem-image_processing>=1.2<2:graphics/rubygem-image_processing \
		rubygem-jbuilder-rails60>=0:devel/rubygem-jbuilder-rails60 \
		rubygem-nokogiri>=1.8.1:textproc/rubygem-nokogiri \
		rubygem-puma>=0:www/rubygem-puma \
		rubygem-rake>=11.1:devel/rubygem-rake \
		rubygem-sass-rails-rails60>=0:textproc/rubygem-sass-rails-rails60 \
		rubygem-selenium-webdriver>=4.11.0:www/rubygem-selenium-webdriver \
		rubygem-spring>=0:devel/rubygem-spring \
		rubygem-sqlite3>=1.4:databases/rubygem-sqlite3 \
		rubygem-turbolinks>=5<6:www/rubygem-turbolinks \
		rubygem-uglifier>=1.3.0:www/rubygem-uglifier \
		rubygem-web-console-rails60>=3.3.0:devel/rubygem-web-console-rails60 \
		rubygem-webmock>=0:www/rubygem-webmock \
		rubygem-webpacker4-rails60>=4.0<5:devel/rubygem-webpacker4-rails60

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^6\.0\.

.include <bsd.port.mk>

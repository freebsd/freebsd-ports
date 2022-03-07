PORTNAME=	rails
PORTVERSION=	7.0.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-stack web application framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actioncable70>=${PORTVERSION}:www/rubygem-actioncable70 \
		rubygem-actionmailbox70>=${PORTVERSION}:mail/rubygem-actionmailbox70 \
		rubygem-actionmailer70>=${PORTVERSION}:mail/rubygem-actionmailer70 \
		rubygem-actionpack70>=${PORTVERSION}:www/rubygem-actionpack70 \
		rubygem-actiontext70>=${PORTVERSION}:textproc/rubygem-actiontext70 \
		rubygem-actionview70>=${PORTVERSION}:devel/rubygem-actionview70 \
		rubygem-activejob70>=${PORTVERSION}:devel/rubygem-activejob70 \
		rubygem-activemodel70>=${PORTVERSION}:databases/rubygem-activemodel70 \
		rubygem-activerecord70>=${PORTVERSION}:databases/rubygem-activerecord70 \
		rubygem-activestorage70>=${PORTVERSION}:net/rubygem-activestorage70 \
		rubygem-activesupport70>=${PORTVERSION}:devel/rubygem-activesupport70 \
		rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-railties70>=${PORTVERSION}:www/rubygem-railties70 \
		rubygem-bootsnap>=1.4.4:devel/rubygem-bootsnap \
		rubygem-capybara>=3.26:devel/rubygem-capybara \
		rubygem-connection_pool>=0:net/rubygem-connection_pool \
		rubygem-cssbundling-rails>=0:www/rubygem-cssbundling-rails \
		rubygem-dalli>=3.0.1:databases/rubygem-dalli \
		rubygem-image_processing>=1.2<2:graphics/rubygem-image_processing \
		rubygem-importmap-rails>=0:www/rubygem-importmap-rails \
		rubygem-jsbundling-rails>=0:www/rubygem-jsbundling-rails \
		rubygem-json>=2.0.0:devel/rubygem-json \
		rubygem-libxml-ruby>=0:textproc/rubygem-libxml-ruby \
		rubygem-listen>=3.3<4:devel/rubygem-listen \
		rubygem-minitest>=5.15.0:devel/rubygem-minitest \
		rubygem-nokogiri>=1.8.1:textproc/rubygem-nokogiri \
		rubygem-propshaft>=0.1.7:www/rubygem-propshaft \
		rubygem-puma>=0:www/rubygem-puma \
		rubygem-que>=0:devel/rubygem-que \
		rubygem-rack-cache>=1.2<2:www/rubygem-rack-cache \
		rubygem-rake>=11.1:devel/rubygem-rake \
		rubygem-redis-namespace>=0:databases/rubygem-redis-namespace \
		rubygem-rexml>=0:textproc/rubygem-rexml \
		rubygem-selenium-webdriver>=4.0.0:www/rubygem-selenium-webdriver \
		rubygem-sprockets-rails-rails70>=2.0.0:devel/rubygem-sprockets-rails-rails70 \
		rubygem-sqlite3>=1.4<2:databases/rubygem-sqlite3 \
		rubygem-stimulus-rails>=0:www/rubygem-stimulus-rails \
		rubygem-sucker_punch>=0:devel/rubygem-sucker_punch \
		rubygem-tailwindcss-rails>=0:www/rubygem-tailwindcss-rails \
		rubygem-turbo-rails>=0:www/rubygem-turbo-rails \
		rubygem-webdrivers>=0:www/rubygem-webdrivers \
		rubygem-webmock>=0:www/rubygem-webmock \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>

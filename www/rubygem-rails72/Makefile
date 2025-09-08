PORTNAME=	rails
PORTVERSION=	7.2.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-stack web application framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actioncable72>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actioncable72 \
		rubygem-actionmailbox72>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailbox72 \
		rubygem-actionmailer72>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailer72 \
		rubygem-actionpack72>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack72 \
		rubygem-actiontext72>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-actiontext72 \
		rubygem-actionview72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview72 \
		rubygem-activejob72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob72 \
		rubygem-activemodel72>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel72 \
		rubygem-activerecord72>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord72 \
		rubygem-activestorage72>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage72 \
		rubygem-activesupport72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport72 \
		rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-railties72>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-railties72 \
		rubygem-bootsnap>=1.4.4:devel/rubygem-bootsnap \
		rubygem-capybara>=3.39:devel/rubygem-capybara \
		rubygem-connection_pool>=0:net/rubygem-connection_pool \
		rubygem-cssbundling-rails-rails72>=0:www/rubygem-cssbundling-rails-rails72 \
		rubygem-dalli>=3.0.1:databases/rubygem-dalli \
		rubygem-image_processing>=1.2<2:graphics/rubygem-image_processing \
		rubygem-importmap-rails-rails72>=1.2.3:www/rubygem-importmap-rails-rails72 \
		rubygem-jbuilder-rails72>=0:devel/rubygem-jbuilder-rails72 \
		rubygem-jsbundling-rails-rails72>=0:www/rubygem-jsbundling-rails-rails72 \
		rubygem-json>=2.0.0:devel/rubygem-json \
		rubygem-launchy>=0:devel/rubygem-launchy \
		rubygem-libxml-ruby>=0:textproc/rubygem-libxml-ruby \
		rubygem-listen>=3.3<4:devel/rubygem-listen \
		rubygem-minitest>=0:devel/rubygem-minitest \
		rubygem-msgpack>=1.7.0:devel/rubygem-msgpack \
		rubygem-nokogiri>=1.8.1:textproc/rubygem-nokogiri \
		rubygem-prism>=0:textproc/rubygem-prism \
		rubygem-propshaft-rails72>=0.1.7:www/rubygem-propshaft-rails72 \
		rubygem-puma>=5.0.3:www/rubygem-puma \
		rubygem-rack>=3.0,3<4,3:www/rubygem-rack \
		rubygem-rack-cache>=1.2<2:www/rubygem-rack-cache \
		rubygem-rake>=13:devel/rubygem-rake \
		rubygem-readline-ext>=0:devel/rubygem-readline-ext \
		rubygem-redis-namespace>=0:databases/rubygem-redis-namespace \
		rubygem-rexml>=0:textproc/rubygem-rexml \
		rubygem-selenium-webdriver>=4.20.0:www/rubygem-selenium-webdriver \
		rubygem-solid_cable-rails72>=0:databases/rubygem-solid_cable-rails72 \
		rubygem-solid_cache-rails72>=0:databases/rubygem-solid_cache-rails72 \
		rubygem-solid_queue-rails72>=0:databases/rubygem-solid_queue-rails72 \
		rubygem-sprockets-rails-rails72>=2.0.0:devel/rubygem-sprockets-rails-rails72 \
		rubygem-sqlite3>=1.6.6:databases/rubygem-sqlite3 \
		rubygem-stimulus-rails-rails72>=0:www/rubygem-stimulus-rails-rails72 \
		rubygem-sucker_punch>=0:devel/rubygem-sucker_punch \
		rubygem-tailwindcss-rails-rails72>=0:www/rubygem-tailwindcss-rails-rails72 \
		rubygem-turbo-rails-rails72>=0:www/rubygem-turbo-rails-rails72 \
		rubygem-web-console-rails72>=0:devel/rubygem-web-console-rails72 \
		rubygem-webmock>=0:www/rubygem-webmock \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^7\.2\.

.include <bsd.port.mk>

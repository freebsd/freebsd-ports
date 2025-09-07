PORTNAME=	rails
PORTVERSION=	8.0.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-stack web application framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actioncable80>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actioncable80 \
		rubygem-actionmailbox80>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailbox80 \
		rubygem-actionmailer80>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailer80 \
		rubygem-actionpack80>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack80 \
		rubygem-actiontext80>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-actiontext80 \
		rubygem-actionview80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview80 \
		rubygem-activejob80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob80 \
		rubygem-activemodel80>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel80 \
		rubygem-activerecord80>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord80 \
		rubygem-activestorage80>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage80 \
		rubygem-activesupport80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport80 \
		rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-railties80>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-railties80 \
		rubygem-bootsnap>=1.4.4:devel/rubygem-bootsnap \
		rubygem-capybara>=3.39:devel/rubygem-capybara \
		rubygem-connection_pool>=0:net/rubygem-connection_pool \
		rubygem-cssbundling-rails>=0:www/rubygem-cssbundling-rails \
		rubygem-dalli>=3.0.1:databases/rubygem-dalli \
		rubygem-image_processing>=1.2<2:graphics/rubygem-image_processing \
		rubygem-importmap-rails>=1.2.3:www/rubygem-importmap-rails \
		rubygem-jbuilder-rails80>=0:devel/rubygem-jbuilder-rails80 \
		rubygem-jsbundling-rails>=0:www/rubygem-jsbundling-rails \
		rubygem-json>=2.0.0:devel/rubygem-json \
		rubygem-kamal>=2.1.0:www/rubygem-kamal \
		rubygem-launchy>=0:devel/rubygem-launchy \
		rubygem-libxml-ruby>=0:textproc/rubygem-libxml-ruby \
		rubygem-listen>=3.3<4:devel/rubygem-listen \
		rubygem-minitest>=0:devel/rubygem-minitest \
		rubygem-msgpack>=1.7.0:devel/rubygem-msgpack \
		rubygem-nokogiri>=1.8.1:textproc/rubygem-nokogiri \
		rubygem-prism>=0:textproc/rubygem-prism \
		rubygem-propshaft>=0.1.7:www/rubygem-propshaft \
		rubygem-puma>=5.0.3:www/rubygem-puma \
		rubygem-rack>=3.0,3<4,3:www/rubygem-rack \
		rubygem-rack-cache>=1.2<2:www/rubygem-rack-cache \
		rubygem-rake>=13:devel/rubygem-rake \
		rubygem-readline-ext>=0:devel/rubygem-readline-ext \
		rubygem-redis-namespace>=0:databases/rubygem-redis-namespace \
		rubygem-rexml>=0:textproc/rubygem-rexml \
		rubygem-selenium-webdriver>=4.20.0:www/rubygem-selenium-webdriver \
		rubygem-solid_cable>=0:databases/rubygem-solid_cable \
		rubygem-solid_cache>=0:databases/rubygem-solid_cache \
		rubygem-solid_queue>=0:databases/rubygem-solid_queue \
		rubygem-sprockets-rails-rails80>=2.0.0:devel/rubygem-sprockets-rails-rails80 \
		rubygem-sqlite3>=2.1.0:databases/rubygem-sqlite3 \
		rubygem-stimulus-rails>=0:www/rubygem-stimulus-rails \
		rubygem-sucker_punch>=0:devel/rubygem-sucker_punch \
		rubygem-tailwindcss-rails>=0:www/rubygem-tailwindcss-rails \
		rubygem-thruster>=0:www/rubygem-thruster \
		rubygem-turbo-rails>=0:www/rubygem-turbo-rails \
		rubygem-web-console-rails80>=0:devel/rubygem-web-console-rails80 \
		rubygem-webmock>=0:www/rubygem-webmock \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^8\.0\.

.include <bsd.port.mk>

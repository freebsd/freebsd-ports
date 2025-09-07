PORTNAME=	rails
PORTVERSION=	7.1.5.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-stack web application framework
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actioncable71>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actioncable71 \
		rubygem-actionmailbox71>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailbox71 \
		rubygem-actionmailer71>=${PORTVERSION}<${PORTVERSION}_99:mail/rubygem-actionmailer71 \
		rubygem-actionpack71>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack71 \
		rubygem-actiontext71>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-actiontext71 \
		rubygem-actionview71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-actionview71 \
		rubygem-activejob71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob71 \
		rubygem-activemodel71>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activemodel71 \
		rubygem-activerecord71>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord71 \
		rubygem-activestorage71>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage71 \
		rubygem-activesupport71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport71 \
		rubygem-bundler>=1.15.0:sysutils/rubygem-bundler \
		rubygem-railties71>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-railties71 \
		rubygem-bootsnap>=1.4.4:devel/rubygem-bootsnap \
		rubygem-capybara>=3.39:devel/rubygem-capybara \
		rubygem-connection_pool>=0:net/rubygem-connection_pool \
		rubygem-cssbundling-rails-rails71>=0:www/rubygem-cssbundling-rails-rails71 \
		rubygem-dalli>=3.0.1:databases/rubygem-dalli \
		rubygem-image_processing>=1.2<2:graphics/rubygem-image_processing \
		rubygem-importmap-rails-rails71>=0:www/rubygem-importmap-rails-rails71 \
		rubygem-jbuilder-rails71>=0:devel/rubygem-jbuilder-rails71 \
		rubygem-jsbundling-rails-rails71>=0:www/rubygem-jsbundling-rails-rails71 \
		rubygem-json>=2.0.0:devel/rubygem-json \
		rubygem-libxml-ruby>=0:textproc/rubygem-libxml-ruby \
		rubygem-listen>=3.3<4:devel/rubygem-listen \
		rubygem-minitest>=5.15.0:devel/rubygem-minitest \
		rubygem-msgpack>=1.7.0:devel/rubygem-msgpack \
		rubygem-nokogiri>=1.8.1:textproc/rubygem-nokogiri \
		rubygem-propshaft-rails71>=0.1.7:www/rubygem-propshaft-rails71 \
		rubygem-puma>=5.0.3:www/rubygem-puma \
		rubygem-rack>=3.0,3<4,3:www/rubygem-rack \
		rubygem-rack-cache>=1.2<2:www/rubygem-rack-cache \
		rubygem-rake>=13:devel/rubygem-rake \
		rubygem-readline-ext>=0:devel/rubygem-readline-ext \
		rubygem-redis-namespace>=0:databases/rubygem-redis-namespace \
		rubygem-rexml>=0:textproc/rubygem-rexml \
		rubygem-selenium-webdriver>=4.11.0:www/rubygem-selenium-webdriver \
		rubygem-sprockets-rails-rails71>=2.0.0:devel/rubygem-sprockets-rails-rails71 \
		rubygem-sqlite3>=1.6.6:databases/rubygem-sqlite3 \
		rubygem-stimulus-rails-rails71>=0:www/rubygem-stimulus-rails-rails71 \
		rubygem-sucker_punch>=0:devel/rubygem-sucker_punch \
		rubygem-tailwindcss-rails-rails71>=0:www/rubygem-tailwindcss-rails-rails71 \
		rubygem-turbo-rails-rails71>=0:www/rubygem-turbo-rails-rails71 \
		rubygem-web-console-rails71>=0:devel/rubygem-web-console-rails71 \
		rubygem-webmock>=0:www/rubygem-webmock \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	ruby_on_rails

PORTSCOUT=	limit:^7\.1\.

.include <bsd.port.pre.mk>

.if ${RUBY_VER} <= 3.1
RUN_DEPENDS+=	rubygem-cgi>=0.3.6:www/rubygem-cgi
.endif

.if ${RUBY_VER} == 3.1
RUN_DEPENDS+=	rubygem-error_highlight>=0.4.0:devel/rubygem-error_highlight
.endif

.include <bsd.port.post.mk>

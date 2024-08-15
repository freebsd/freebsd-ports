PORTNAME=	bullet_train
PORTVERSION=	1.7.20
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bullet Train, Open Source Ruby on Rails SaaS Framework
WWW=		https://bullettrain.co/ \
		https://github.com/bullet-train-co/bullet_train-core/tree/main/bullet_train

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-awesome_print>=0:devel/rubygem-awesome_print \
		rubygem-bullet_train-has_uuid>=0:www/rubygem-bullet_train-has_uuid \
		rubygem-bullet_train-roles>=0:www/rubygem-bullet_train-roles \
		rubygem-bullet_train-routes>=0:www/rubygem-bullet_train-routes \
		rubygem-bullet_train-scope_validator>=0:www/rubygem-bullet_train-scope_validator \
		rubygem-bullet_train-super_load_and_authorize_resource>=0:www/rubygem-bullet_train-super_load_and_authorize_resource \
		rubygem-bullet_train-themes>=0:www/rubygem-bullet_train-themes \
		rubygem-cable_ready>=5.0.0<5.1:www/rubygem-cable_ready \
		rubygem-cancancan>=0:security/rubygem-cancancan \
		rubygem-colorizer>=0:devel/rubygem-colorizer \
		rubygem-commonmarker>=1.0.0:textproc/rubygem-commonmarker \
		rubygem-devise-pwned_password>=0:devel/rubygem-devise-pwned_password \
		rubygem-devise-rails71>=0:devel/rubygem-devise-rails71 \
		rubygem-extended_email_reply_parser>=0:mail/rubygem-extended_email_reply_parser \
		rubygem-fastimage>=0:graphics/rubygem-fastimage \
		rubygem-figaro>=0:devel/rubygem-figaro \
		rubygem-hiredis>=0:databases/rubygem-hiredis \
		rubygem-http_accept_language>=0:devel/rubygem-http_accept_language \
		rubygem-image_processing>=0:graphics/rubygem-image_processing \
		rubygem-microscope>=0:databases/rubygem-microscope \
		rubygem-nice_partials>=0.9<1:devel/rubygem-nice_partials \
		rubygem-omniauth>=0:security/rubygem-omniauth \
		rubygem-pagy>=0:devel/rubygem-pagy \
		rubygem-possessive>=0:www/rubygem-possessive \
		rubygem-premailer-rails-rails71>=0:mail/rubygem-premailer-rails-rails71 \
		rubygem-rails71>=6.0.0:www/rubygem-rails71 \
		rubygem-ruby-openai>=0:www/rubygem-ruby-openai \
		rubygem-showcase-rails>=0:www/rubygem-showcase-rails \
		rubygem-sidekiq>=0:devel/rubygem-sidekiq \
		rubygem-unicode-emoji>=0:devel/rubygem-unicode-emoji \
		rubygem-valid_email02>=0:mail/rubygem-valid_email02 \
		rubygem-xxhash>=0:devel/rubygem-xxhash

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

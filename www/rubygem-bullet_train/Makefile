PORTNAME=	bullet_train
PORTVERSION=	1.37.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bullet Train, Open Source Ruby on Rails SaaS Framework
WWW=		https://bullettrain.co/ \
		https://github.com/bullet-train-co/bullet_train-core/tree/main/bullet_train

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-bullet_train-has_uuid>=0:www/rubygem-bullet_train-has_uuid \
		rubygem-bullet_train-roles>=0:www/rubygem-bullet_train-roles \
		rubygem-bullet_train-fields>=0:www/rubygem-bullet_train-fields \
		rubygem-bullet_train-scope_validator>=0:www/rubygem-bullet_train-scope_validator \
		rubygem-bullet_train-super_load_and_authorize_resource>=0:www/rubygem-bullet_train-super_load_and_authorize_resource \
		rubygem-bullet_train-themes>=0:www/rubygem-bullet_train-themes \
		rubygem-cable_ready>=5.0.0<5.1:www/rubygem-cable_ready \
		rubygem-cancancan>=0:security/rubygem-cancancan \
		rubygem-colorize>=0:devel/rubygem-colorize \
		rubygem-commonmarker>=1.0.0:textproc/rubygem-commonmarker \
		rubygem-devise-pwned_password>=0:devel/rubygem-devise-pwned_password \
		rubygem-devise-rails81>=0:devel/rubygem-devise-rails81 \
		rubygem-fastimage>=0:graphics/rubygem-fastimage \
		rubygem-figaro>=0:devel/rubygem-figaro \
		rubygem-http_accept_language>=0:devel/rubygem-http_accept_language \
		rubygem-nice_partials>=0.9<1:devel/rubygem-nice_partials \
		rubygem-omniauth>=2<3:security/rubygem-omniauth \
		rubygem-pagy>=9:devel/rubygem-pagy \
		rubygem-possessive>=0:www/rubygem-possessive \
		rubygem-rails81>=6.0.0:www/rubygem-rails81 \
		rubygem-showcase-rails>=0:www/rubygem-showcase-rails

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

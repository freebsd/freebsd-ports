PORTNAME=	bullet_train-themes
PORTVERSION=	1.7.20
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bullet Train Themes
WWW=		https://github.com/bullet-train-co/bullet_train-core/tree/main/bullet_train-themes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-bullet_train-fields>=0:www/rubygem-bullet_train-fields \
		rubygem-nice_partials>=0.9<1:devel/rubygem-nice_partials \
		rubygem-rails71>=6.0.0:www/rubygem-rails71

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

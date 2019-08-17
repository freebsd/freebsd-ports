# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sass-rails
PORTVERSION=	5.0.7
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sass adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties50>=4.0.0<6:www/rubygem-railties50 \
		rubygem-sass>=3.1<4:textproc/rubygem-sass \
		rubygem-sprockets3>=2.8<4.0:devel/rubygem-sprockets3 \
		rubygem-sprockets-rails-rails50>=2.0<4.0:devel/rubygem-sprockets-rails-rails50 \
		rubygem-tilt>=1.1<3:devel/rubygem-tilt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# It requires Rails 5.2.0+ since 5.0.8.
PORTSCOUT=	ignore:1

.include <bsd.port.mk>

# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sass-rails
PORTVERSION=	5.1.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sass adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties52>=5.2.0:www/rubygem-railties52 \
		rubygem-sass>=3.1<4:textproc/rubygem-sass \
		rubygem-sprockets3>=2.8<4.0:devel/rubygem-sprockets3 \
		rubygem-sprockets-rails-rails52>=2.0<4.0:devel/rubygem-sprockets-rails-rails52 \
		rubygem-tilt>=1.1<3:devel/rubygem-tilt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>

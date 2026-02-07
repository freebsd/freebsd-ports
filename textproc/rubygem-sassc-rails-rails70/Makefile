PORTNAME=	sassc-rails
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Integrate SassC-Ruby into Rails
WWW=		https://github.com/sass/sassc-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties70>=4.0.0:www/rubygem-railties70 \
		rubygem-sassc>=2.0:textproc/rubygem-sassc \
		rubygem-sprockets-rails-rails70>=0:devel/rubygem-sprockets-rails-rails70 \
		rubygem-sprockets3>=3.0:devel/rubygem-sprockets3 \
		rubygem-tilt>=0:devel/rubygem-tilt

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

# Created by: Johannes Jost Meixner <xmj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sass-rails
PORTVERSION=	5.0.7
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sass adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties4>=4.0.0:www/rubygem-railties4 \
		rubygem-sass>=3.1:textproc/rubygem-sass \
		rubygem-sprockets3>=3.0.3:devel/rubygem-sprockets3 \
		rubygem-sprockets-rails>=2.0:devel/rubygem-sprockets-rails \
		rubygem-tilt>=1.1:devel/rubygem-tilt

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>

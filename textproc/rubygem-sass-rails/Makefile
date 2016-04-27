# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sass-rails
PORTVERSION=	3.2.6
PORTREVISION=	4
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sass adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties>=3.2.0:www/rubygem-railties \
		rubygem-sass>=3.3.4:textproc/rubygem-sass \
		rubygem-tilt>=2.0.1:devel/rubygem-tilt

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>

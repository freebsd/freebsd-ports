# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	autoprefixer-rails
PORTVERSION=	10.2.0.0
CATEGORIES=	textproc ruby
MASTER_SITES=	RG
PKGNAMESUFFIX=	1020

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse CSS and add vendor prefixes to CSS rules

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-execjs>=0:devel/rubygem-execjs

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^10\.2\.0\.

.include <bsd.port.mk>

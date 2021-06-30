# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cucumber-html-formatter
PORTVERSION=	13.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	13

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML formatter for Cucumber

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages15>=15.0.0<16:devel/rubygem-cucumber-messages15

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber-html-formatter

PORTSCOUT=	limit:^13\.

.include <bsd.port.mk>

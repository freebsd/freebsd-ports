# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cucumber-html-formatter
PORTVERSION=	17.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	17

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML formatter for Cucumber

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages>=17.1.0<18:devel/rubygem-cucumber-messages

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber-html-formatter

PORTSCOUT=	limit:^17\.

.include <bsd.port.mk>

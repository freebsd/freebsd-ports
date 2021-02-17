# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cucumber-html-formatter
PORTVERSION=	9.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	9

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML formatter for Cucumber

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages13>=13.0.1<14:devel/rubygem-cucumber-messages13

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber-html-formatter

PORTSCOUT=	limit:^9\.

.include <bsd.port.mk>

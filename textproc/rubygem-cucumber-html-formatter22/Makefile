PORTNAME=	cucumber-html-formatter
PORTVERSION=	22.3.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	22

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML formatter for Cucumber
WWW=		https://github.com/cucumber/html-formatter

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages>=23<33:devel/rubygem-cucumber-messages

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/cucumber-html-formatter

PORTSCOUT=	limit:^22\.

.include <bsd.port.mk>

PORTNAME=	cucumber-html-formatter
PORTVERSION=	21.15.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	21

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML formatter for Cucumber
WWW=		https://github.com/cucumber/html-formatter

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages27>=19<28:devel/rubygem-cucumber-messages27

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^21\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/cucumber-html-formatter

.include <bsd.port.mk>

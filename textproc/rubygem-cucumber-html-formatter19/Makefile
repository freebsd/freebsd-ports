PORTNAME=	cucumber-html-formatter
PORTVERSION=	19.2.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	19

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML formatter for Cucumber
WWW=		https://github.com/cucumber/html-formatter

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages18>=18.0.0<19:devel/rubygem-cucumber-messages18

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^19\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/cucumber-html-formatter

.include <bsd.port.mk>

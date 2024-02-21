PORTNAME=	cucumber-gherkin
PORTVERSION=	27.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	27

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler
WWW=		https://github.com/cucumber/gherkin

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages22>=19.1.4<23:devel/rubygem-cucumber-messages22

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^27\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/gherkin ${STAGEDIR}${PREFIX}/bin/gherkin-ruby

.include <bsd.port.mk>

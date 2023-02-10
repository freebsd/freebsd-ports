PORTNAME=	cucumber-gherkin
PORTVERSION=	23.0.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	23

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler
WWW=		https://github.com/cucumber/common/tree/main/gherkin/ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-messages18>=18.0.0<19:devel/rubygem-cucumber-messages18

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^23\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/gherkin ${STAGEDIR}${PREFIX}/bin/gherkin-ruby

.include <bsd.port.mk>

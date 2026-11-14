PORTNAME=	cucumber-gherkin
PORTVERSION=	42.0.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	42

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler
WWW=		https://github.com/cucumber/gherkin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-messages34>=34<35:devel/rubygem-cucumber-messages34

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^42\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/gherkin ${STAGEDIR}${PREFIX}/bin/gherkin-ruby

.include <bsd.port.mk>

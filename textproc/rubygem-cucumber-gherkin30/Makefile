PORTNAME=	cucumber-gherkin
PORTVERSION=	30.0.4
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	30

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler
WWW=		https://github.com/cucumber/gherkin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-messages27>=25<28:devel/rubygem-cucumber-messages27

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^30\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/gherkin ${STAGEDIR}${PREFIX}/bin/gherkin-ruby

.include <bsd.port.mk>

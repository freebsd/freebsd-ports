PORTNAME=	cucumber-gherkin
PORTVERSION=	29.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler
WWW=		https://github.com/cucumber/gherkin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cucumber-messages25>=25<26:devel/rubygem-cucumber-messages25

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/gherkin \
		bin/gherkin-ruby

.include <bsd.port.mk>

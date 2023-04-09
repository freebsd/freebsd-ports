PORTNAME=	cucumber-gherkin
PORTVERSION=	26.2.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler
WWW=		https://github.com/cucumber/gherkin

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages>=19.1.4<22.1:devel/rubygem-cucumber-messages

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/gherkin \
		bin/gherkin-ruby

.include <bsd.port.mk>

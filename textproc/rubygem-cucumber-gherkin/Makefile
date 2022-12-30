PORTNAME=	cucumber-gherkin
PORTVERSION=	25.0.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast Gherkin lexer/parser based on the Ragel State Machine Compiler
WWW=		https://github.com/cucumber/gherkin

LICENSE=	MIT

RUN_DEPENDS=	rubygem-cucumber-messages19>=19.1.4<20:devel/rubygem-cucumber-messages19

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gherkin \
		bin/gherkin-ruby

.include <bsd.port.mk>
